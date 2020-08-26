#pragma once

#include <numeric>
#include <string>
#include <vector>

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
  HIT,           // 命中
  CRIT,          // 暴击
  ATTACK_POWER,  // 攻击强度
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

template <typename StatT>
struct Gear {
  Gear(const std::string& gear_name, Slot gear_slot, StatT strength,
       StatT agility, StatT stamina, StatT armor, StatT defence = 0,
       StatT dodge = 0, StatT parry = 0, StatT block = 0, StatT block_value = 0,
       StatT hit = 0, StatT crit = 0, StatT ap = 0);
  std::string name;
  Slot slot;
  StatT stats[STAT_NUM];
};

template <typename StatT, typename WeightT>
struct StatWeight {
  WeightT stats[STAT_NUM];
  WeightT hit_over_threshold;
  StatT hit_threshold;
};

template <typename StatT, typename WeightT, typename SlotT>
class GearCalculator {
 public:
  void SetGears(const std::vector<Gear<StatT>>& heads,
                const std::vector<Gear<StatT>>& necks,
                const std::vector<Gear<StatT>>& shoulder,
                const std::vector<Gear<StatT>>& backs,
                const std::vector<Gear<StatT>>& chests,
                const std::vector<Gear<StatT>>& wrists,
                const std::vector<Gear<StatT>>& hands,
                const std::vector<Gear<StatT>>& waists,
                const std::vector<Gear<StatT>>& legs,
                const std::vector<Gear<StatT>>& feet,
                const std::vector<Gear<StatT>>& fingers,
                const std::vector<Gear<StatT>>& trinkets,
                const std::vector<Gear<StatT>>& ranged);
  void SetWeight(WeightT strength, WeightT agility, WeightT stamina,
                 WeightT armor, WeightT defence, WeightT dodge, WeightT parry,
                 WeightT block, WeightT block_value, WeightT hit,
                 WeightT hit_over_threshold, WeightT crit, WeightT ap,
                 StatT hit_threshold);
  void Calculate();

 private:
  std::vector<Gear<StatT>> gears_[SLOT_NUM];
  StatWeight<StatT, WeightT> weight_;

  std::vector<SlotT[SLOT_NUM_TWO_FINGER]> all_;
};
