#include "core.h"

#include <cstdint>
#include <iostream>
#include <fstream>

#include <boost/algorithm/algorithm.hpp>

std::vector<Gear> LoadGears(std::ifstream& ifs, Slot slot) {
  std::vector<Gear> gears{};
  std::string line;
  if (!std::getline(ifs, line)) {
    return gears;
  }
  while (std::getline(ifs, line)) {
    if (line.empty() || line[0] == '-') {
      break;
    }
    
  }
}


int main() {
  GearCalculator calculator;
  calculator.SetGears(heads, necks, shoulders, backs, chests, wrists, hands,
                      waists, legs, feet, fingers, trinckets, rangeds);

  // Main stats:
  // https://classic.wowhead.com/guides/classic-wow-stats-and-attributes-overview

  // Armor formula:
  // https://us.forums.blizzard.com/en/wow/t/the-armor-cap/318067
  // reduction = armor / (armor + 400 + 85 * target_level)
  // 0.75 = 17265 / (17265 + 400 + 85 * 63)
  calculator.SetWeight(
     2,     // 力量 = 2 AP + 0.05 格挡值
     2.5,   // 敏捷 = 0.05 暴击 + 0.05 躲闪 + 2 护甲
     3,     // 耐力 = 10 血量
     0.07,  // 护甲 = 大约 160-200 护甲可以提供 1% 免伤
     2.16,  // 防御等级 = 0.04% 闪、招、格挡、未命中、免爆
     15,    // 闪躲
     12,    // 招架
     0,     // 格挡
     0,     // 格挡值
     50,    // 命中
     1,     // 超过阈值的命中
     30,    // 暴击 = 0.01 / (1 + 当前暴击%) 的伤害提升
     1,     // AP
     6,     // 命中阈值
     0.25); // 主属性加成
  calculator.Calculate();
  return 0;
}
