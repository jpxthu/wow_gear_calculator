#include "core.h"

#include <array>
#include <iostream>
#include <fstream>
#include <limits>

Gear::Gear(const std::string& gear_name, Slot gear_slot,
           StatT strength, StatT agility, StatT stamina,
           StatT armor, StatT defence, StatT dodge, StatT parry,
           StatT block, StatT block_value, StatT hit, StatT crit,
           StatT ap)
    : name(gear_name), slot(gear_slot) {
  stats[STRENGTH] = strength;
  stats[AGILITY] = agility;
  stats[STAMINA] = stamina;
  stats[ARMOR] = armor;
  stats[DEFENCE] = defence;
  stats[DODGE] = dodge;
  stats[PARRY] = parry;
  stats[BLOCK] = block;
  stats[BLOCK_VALUE] = block_value;
  stats[HIT] = hit;
  stats[CRIT] = crit;
  stats[ATTACK_POWER] = ap;
}

Solution::Solution(const GearT* const gears_index,
                   const std::vector<Gear>* const gears,
                   const StatWeight& stat_weight,
                   float main_enhance_percentage) {
  for (int stat_i = 0; stat_i < STAT_NUM; stat_i++) {
    stats_[stat_i] = StatT(0);
  }
  for (GearT i = 0; i < SLOT_NUM_TWO_FINGER; i++) {
    GearT index = gears_index[i];
    const Gear* gear = &gears[i == FINGER + 1 ? FINGER : i][index];
    gears_[i] = (Gear*)gear;
    for (int stat_i = 0; stat_i < STAT_NUM; stat_i++) {
      stats_[stat_i] += gear->stats[stat_i];
    }
  }
  stats_[STRENGTH] += StatT(stats_[STRENGTH] * main_enhance_percentage);
  stats_[AGILITY] += StatT(stats_[AGILITY] * main_enhance_percentage);
  stats_[STAMINA] += StatT(stats_[STAMINA] * main_enhance_percentage);
  score_ = WeightT(0);
  for (int stat_i = 0; stat_i < STAT_NUM; stat_i++) {
    score_ += stats_[stat_i] * stat_weight.stats[stat_i];
  }
  if (stats_[HIT] > stat_weight.hit_threshold) {
    score_ -= (stat_weight.stats[HIT] - stat_weight.hit_over_threshold)
                  * (stats_[HIT] - stat_weight.hit_threshold);
  }
}

WeightT Solution::Score() const {
  return score_;
}

StatT Solution::Stat(StatType stat_type) const {
  return stats_[stat_type];
}

const std::string& Solution::GearName(Slot slot) const {
  return gears_[slot]->name;
}

void GearCalculator::SetGears(
    const std::vector<Gear>& heads,
    const std::vector<Gear>& necks,
    const std::vector<Gear>& shoulder,
    const std::vector<Gear>& backs,
    const std::vector<Gear>& chests,
    const std::vector<Gear>& wrists,
    const std::vector<Gear>& hands,
    const std::vector<Gear>& waists,
    const std::vector<Gear>& legs, const std::vector<Gear>& feet,
    const std::vector<Gear>& fingers,
    const std::vector<Gear>& trinkets,
    const std::vector<Gear>& ranged) {
  gears_[HEAD] = heads;
  gears_[NECK] = necks;
  gears_[SHOULDER] = shoulder;
  gears_[BACK] = backs;
  gears_[CHEST] = chests;
  gears_[WRIST] = wrists;
  gears_[HAND] = hands;
  gears_[WAIST] = waists;
  gears_[LEG] = legs;
  gears_[FEET] = feet;
  gears_[TRINCKET] = trinkets;
  gears_[RANGED] = ranged;
  gears_[FINGER] = fingers;

  size_t size = fingers.size() * (fingers.size() - 1) / 2;
  for (int i = 0; i < SLOT_NUM; i++) {
    size *= i == FINGER ? 1 : gears_[i].size();
  }

  all_ = std::vector<GearT[SLOT_NUM_TWO_FINGER]>(size);
  for (int i = 0; i <= FINGER; i++) {
    all_[0][i] = 0;
  }
  all_[0][FINGER + 1] = 1;

  const GearT finger_num = fingers.size();
  for (size_t i = 1; i < size; i++) {
    for (int slot = 0; slot < SLOT_NUM_TWO_FINGER; slot++) {
      all_[i][slot] = all_[i - 1][slot];
    }

    GearT v = 0;
    bool carry = true;
    for (int slot = 0; slot < FINGER; slot++) {
      v = all_[i - 1][slot] + 1;
      if (v < gears_[slot].size()) {
        all_[i][slot] = v;
        carry = false;
        break;
      }
      all_[i][slot] = 0;
      carry = true;
    }
    if (!carry) {
      continue;
    }

    v = all_[i - 1][FINGER + 1] + 1;
    if (v < finger_num) {
      all_[i][FINGER + 1] = v;
      continue;
    }

    v = all_[i - 1][FINGER] + 1;
    if (v < finger_num - 1) {
      all_[i][FINGER] = v;
      all_[i][FINGER + 1] = v + 1;
      continue;
    }

    std::cout << "***** " << i << std::endl;
    exit(1);
  }

  return;
  std::cout << "名称,力量,敏捷,耐力,护甲,防御,闪躲,招架,格挡,格挡值,命中,暴击,AP" << std::endl;
  for (const std::vector<Gear>& vg : gears_) {
    for (const Gear& gear : vg) {
      std::cout << gear.name
                << "," << gear.stats[STRENGTH]
                << "," << gear.stats[AGILITY]
                << "," << gear.stats[STAMINA]
                << "," << gear.stats[ARMOR]
                << "," << gear.stats[DEFENCE]
                << "," << gear.stats[DODGE]
                << "," << gear.stats[PARRY]
                << "," << gear.stats[BLOCK]
                << "," << gear.stats[BLOCK_VALUE]
                << "," << gear.stats[HIT]
                << "," << gear.stats[CRIT]
                << "," << gear.stats[ATTACK_POWER] << std::endl;
    }
  }
}

void GearCalculator::SetWeight(
    WeightT strength, WeightT agility, WeightT stamina, WeightT armor,
    WeightT defence, WeightT dodge, WeightT parry, WeightT block,
    WeightT block_value, WeightT hit, WeightT hit_over_threshold, WeightT crit,
    WeightT ap, StatT hit_threshold, float main_enhance_percentage) {
  weight_.stats[STRENGTH] = strength;
  weight_.stats[AGILITY] = agility;
  weight_.stats[STAMINA] = stamina;
  weight_.stats[ARMOR] = armor;
  weight_.stats[DEFENCE] = defence;
  weight_.stats[DODGE] = dodge;
  weight_.stats[PARRY] = parry;
  weight_.stats[BLOCK] = block;
  weight_.stats[BLOCK_VALUE] = block_value;
  weight_.stats[HIT] = hit;
  weight_.stats[CRIT] = crit;
  weight_.stats[ATTACK_POWER] = ap;
  weight_.hit_threshold = hit_threshold;
  weight_.hit_over_threshold = hit_over_threshold;
  main_enhance_percentage_ = main_enhance_percentage;
}

void GearCalculator::Calculate() {
  constexpr size_t kSolutionNum = 100;
  solutions_ = std::vector<Solution>(
      kSolutionNum, Solution(-std::numeric_limits<float>::infinity()));

  for (const auto& sets : all_) {
    Solution solution = Solution(sets, gears_, weight_, main_enhance_percentage_);

    for (auto it = solutions_.begin(); it < solutions_.end(); it++) {
      if (solution.Score() > it->Score()) {
        solutions_.pop_back();
        solutions_.insert(it, solution);
        break;
      }
    }
  }
}

void GearCalculator::OutputResult(const std::string& file) const {
  std::ofstream ofs(file);
  ofs << "得分,力量,敏捷,耐力,护甲,防御,闪躲,招架,格挡,格挡值,命中,暴击,AP,"
         "头盔,项链,肩膀,披风,胸甲,护腕,手套,腰带,裤子,鞋,戒指1,戒指2,饰品,远程" << std::endl;
  for (const Solution& solution : solutions_) {
    if (solution.Score() < WeightT(0)) {
      break;
    }

    ofs << solution.Score()
        << "," << solution.Stat(STRENGTH)
        << "," << solution.Stat(AGILITY)
        << "," << solution.Stat(STAMINA)
        << "," << solution.Stat(ARMOR)
        << "," << solution.Stat(DEFENCE)
        << "," << solution.Stat(DODGE)
        << "," << solution.Stat(PARRY)
        << "," << solution.Stat(BLOCK)
        << "," << solution.Stat(BLOCK_VALUE)
        << "," << solution.Stat(HIT)
        << "," << solution.Stat(CRIT)
        << "," << solution.Stat(ATTACK_POWER)
        << "," << solution.GearName(HEAD)
        << "," << solution.GearName(NECK)
        << "," << solution.GearName(SHOULDER)
        << "," << solution.GearName(BACK)
        << "," << solution.GearName(CHEST)
        << "," << solution.GearName(WRIST)
        << "," << solution.GearName(HAND)
        << "," << solution.GearName(WAIST)
        << "," << solution.GearName(LEG)
        << "," << solution.GearName(FEET)
        << "," << solution.GearName(FINGER)
        << "," << solution.GearName(SLOT_NUM)
        << "," << solution.GearName(TRINCKET)
        << "," << solution.GearName(RANGED) << std::endl;
  }
  ofs.close();
}
