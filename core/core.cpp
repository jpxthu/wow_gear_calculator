#include "core.h"

#include <array>
#include <iostream>

template <typename StatT>
Gear<StatT>::Gear<StatT>(const std::string& gear_name, Slot gear_slot,
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

template <typename StatT, typename WeightT, typename SlotT>
void GearCalculator<StatT, WeightT, SlotT>::SetGears(
    const std::vector<Gear<StatT>>& heads,
    const std::vector<Gear<StatT>>& necks,
    const std::vector<Gear<StatT>>& shoulder,
    const std::vector<Gear<StatT>>& backs,
    const std::vector<Gear<StatT>>& chests,
    const std::vector<Gear<StatT>>& wrists,
    const std::vector<Gear<StatT>>& hands,
    const std::vector<Gear<StatT>>& waists,
    const std::vector<Gear<StatT>>& legs, const std::vector<Gear<StatT>>& feet,
    const std::vector<Gear<StatT>>& fingers,
    const std::vector<Gear<StatT>>& trinkets,
    const std::vector<Gear<StatT>>& ranged) {
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

  all_ = std::vector<SlotT[SLOT_NUM_TWO_FINGER]>(size);
  for (int i = 0; i <= FINGER; i++) {
    all_[0][i] = 0;
  }
  all_[0][FINGER + 1] = 1;

  const SlotT finger_num = fingers.size();
  for (size_t i = 1; i < size; i++) {
    for (int slot = 0; slot < SLOT_NUM_TWO_FINGER; slot++) {
      all_[i][slot] = all_[i - 1][slot];
    }

    SlotT v = 0;
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

  std::cout << all_.size() << std::endl;
}

template <typename StatT, typename WeightT, typename SlotT>
void GearCalculator<StatT, WeightT, SlotT>::SetWeight(
    WeightT strength, WeightT agility, WeightT stamina, WeightT armor,
    WeightT defence, WeightT dodge, WeightT parry, WeightT block,
    WeightT block_value, WeightT hit, WeightT hit_over_threshold, WeightT crit,
    WeightT ap, StatT hit_threshold) {
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
}

template <typename StatT, typename WeightT, typename SlotT>
void GearCalculator<StatT, WeightT, SlotT>::Calculate() {
  size_t count[100] = {0};
  for (const auto& sets : all_) {
    StatT hit = 0;
    for (int slot = 0; slot < SLOT_NUM; slot++) {
      SlotT gear_index = sets[slot];
      const Gear<StatT>& gear = gears_[slot][gear_index];
      hit += gear.stats[HIT];
    }
    SlotT gear_index = sets[FINGER + 1];
    const Gear<StatT>& gear = gears_[FINGER][gear_index];
    hit += gear.stats[HIT];
    count[hit]++;
  }

  for (int i = 0; i < 100; i++) {
    std::cout << i << "\t" << count[i] << std::endl;
  }
}
