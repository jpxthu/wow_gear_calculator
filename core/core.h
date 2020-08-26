#pragma once

#include <numeric>
#include <string>
#include <vector>

enum StatType {
  STRENGTH = 0,  // ����
  AGILITY,       // ����
  STAMINA,       // ����
  ARMOR,         // ����
  DEFENCE,       // �����ȼ�
  DODGE,         // ����
  PARRY,         // �м�
  BLOCK,         // ��
  BLOCK_VALUE,   // ��ֵ
  HIT,           // ����
  CRIT,          // ����
  ATTACK_POWER,  // ����ǿ��
  STAT_NUM
};

enum Slot {
  HEAD = 0,  // ͷ��
  NECK,      // ����
  SHOULDER,  // ���
  BACK,      // ����
  CHEST,     // �ؼ�
  WRIST,     // ����
  HAND,      // ����
  WAIST,     // ����
  LEG,       // ����
  FEET,      // Ь
  TRINCKET,  // ��Ʒ
  RANGED,    // Զ��
  FINGER,    // ��ָ
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
