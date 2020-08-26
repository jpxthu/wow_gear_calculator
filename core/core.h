#pragma once

#include <numeric>
#include <string>
#include <vector>

typedef uint8_t GearT;
typedef int16_t StatT;
typedef float WeightT;

enum StatType {
  STRENGTH = 0,  // 力量
  AGILITY,       // 敏捷
  STAMINA,       // 耐力
  ARMOR,         // 护甲
  DEFENCE,       // 防御等级
  DODGE,         // 躲闪
  PARRY,         // 招架
  BLOCK,         // 格挡
  BLOCK_VALUE,   // 格挡值
  CRIT,          // 暴击
  ATTACK_POWER,  // 攻击强度
  HIT,           // 命中
  STAT_NUM
};

enum Slot {
  HEAD = 0,  // 头盔
  NECK,      // 项链
  SHOULDER,  // 肩膀
  BACK,      // 披风
  CHEST,     // 胸甲
  WRIST,     // 手腕
  HAND,      // 手套
  WAIST,     // 腰带
  LEG,       // 裤子
  FEET,      // 鞋
  TRINCKET,  // 饰品
  RANGED,    // 远程
  FINGER,    // 戒指
  SLOT_NUM,
  SLOT_NUM_TWO_FINGER
};

struct Gear {
  Gear(const std::string& gear_name, Slot gear_slot, StatT strength,
       StatT agility, StatT stamina, StatT armor, StatT defence = 0,
       StatT dodge = 0, StatT parry = 0, StatT block = 0, StatT block_value = 0,
       StatT hit = 0, StatT crit = 0, StatT ap = 0);
  Gear() {}
  std::string name;
  Slot slot;
  StatT stats[STAT_NUM];
};

struct StatWeight {
  WeightT stats[STAT_NUM];
  WeightT hit_over_threshold;
  StatT hit_threshold;
};

class Solution {
 public:
  Solution(const GearT* const gears_index,
           const std::vector<Gear>* const gears,
           const StatWeight& stat_weight,
           float main_enhance_percentage);
  Solution(WeightT score) : score_(score) {}

  WeightT Score() const;
  StatT Stat(StatType stat_type) const;
  const std::string& GearName(Slot slot) const;

 private:
  Gear* gears_[SLOT_NUM_TWO_FINGER] = {nullptr};
  StatT stats_[STAT_NUM] = {StatT(0)};
  WeightT score_ = WeightT(0);
};

class GearCalculator {
 public:
  void SetGears(const std::vector<Gear>& heads,
                const std::vector<Gear>& necks,
                const std::vector<Gear>& shoulder,
                const std::vector<Gear>& backs,
                const std::vector<Gear>& chests,
                const std::vector<Gear>& wrists,
                const std::vector<Gear>& hands,
                const std::vector<Gear>& waists,
                const std::vector<Gear>& legs,
                const std::vector<Gear>& feet,
                const std::vector<Gear>& fingers,
                const std::vector<Gear>& trinkets,
                const std::vector<Gear>& ranged);
  void SetWeight(WeightT strength, WeightT agility, WeightT stamina,
                 WeightT armor, WeightT defence, WeightT dodge, WeightT parry,
                 WeightT block, WeightT block_value, WeightT hit,
                 WeightT hit_over_threshold, WeightT crit, WeightT ap,
                 StatT hit_threshold, float main_enhance_percentage = 0.0f);
  void Calculate();
  void OutputResult(const std::string& file) const;

 private:
  std::vector<Gear> gears_[SLOT_NUM];
  StatWeight weight_;
  float main_enhance_percentage_ = 0.0f;

  std::vector<GearT[SLOT_NUM_TWO_FINGER]> all_;
  std::vector<Solution> solutions_;
};
