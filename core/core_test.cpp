#include "core.h"

#include <cstdint>
#include <iostream>

std::vector<Gear<int16_t>> heads = {
    Gear<int16_t>("征服者的皇冠", Slot::HEAD, 29, 18, 34, 739, 6),
    //{"无尽怒气头盔", Slot::HEAD, 26, 26, 29, 679},
}; /*
std::vector<Gear<int16_t>> necks = {
    {"屠龙大师勋章", Slot::NECK, 0, 14, 24, 0, 7},
    {"克苏恩的印记", Slot::NECK, 0, 0, 24, 0, 10, 1, 0, 0, 0, 1},
    {"奥妮克希亚龙牙坠饰", Slot::NECK, 0, 12, 9, 0, 0, 0, 0, 0, 0, 1, 1},
};
std::vector<Gear<int16_t>> shoulders = {
    {"征服者的肩铠", Slot::SHOULDER, 20, 16, 21, 659, 4, 0, 0, 0, 0, 1},
    {"愤怒肩铠", Slot::SHOULDER, 13, 0, 27, 642, 7, 0, 0, 0, 27},
    {"龙爪肩铠", Slot::SHOULDER, 20, 20, 17, 634, 0, 1},
};
std::vector<Gear<int16_t>> backs = {
    {"堕落神明披风", Slot::BACK, 11, 26, 15, 66},
    {"源质丝线披风", Slot::BACK, 0, 0, 13, 169, 0, 2},
    {"坚定力量披风", Slot::BACK, 15, 9, 9, 52, 0, 0, 0, 0, 0, 1},
    {"沙漠风暴披风", Slot::BACK, 12, 0, 12, 135, 6, 1},
    {"金巢披风", Slot::BACK, 13, 10, 19, 59, 6},
};
std::vector<Gear<int16_t>> chests = {
    {"征服者的胸甲", Slot::CHEST, 34, 24, 38, 985, 6},
};
std::vector<Gear<int16_t>> wrists = {
    {"愤怒护腕", Slot::WRIST, 13, 0, 27, 375},
    {"野蛮护腕", Slot::WRIST, 21, 12, 9, 356},
};
std::vector<Gear<int16_t>> hands = {
    {"毁灭护手", Slot::HAND, 35, 0, 15, 615, 0, 0, 0, 0, 0, 1, 1},
    {"愤怒护手", Slot::HAND, 15, 0, 20, 535, 7, 0, 1},
    {"烈焰守卫护手", Slot::HAND, 0, 0, 13, 488, 0, 0, 0, 0, 0, 0, 1, 54},
    {"坚定信念护手", Slot::HAND, 19, 18, 20, 535, 9},
};
std::vector<Gear<int16_t>> waists = {
    {"皇家其拉腰带", Slot::WAIST, 13, 13, 22, 512, 8, 0, 1},
    {"冲击束带", Slot::WAIST, 31, 0, 11, 494, 0, 0, 0, 0, 0, 1, 1},
    {"蔓延腰带", Slot::WAIST, 26, 19, 17, 476},
};
std::vector<Gear<int16_t>> legs = {
    {"征服者的腿铠", Slot::LEG, 33, 21, 24, 796, 6, 0, 0, 0, 0, 1},
    {"愤怒腿铠", Slot::LEG, 19, 0, 27, 749, 11, 2},
};
std::vector<Gear<int16_t>> feet = {
    {"愤怒马靴", Slot::FEET, 13, 0, 30, 589, 7, 0, 0, 0, 14},
    {"多彩长靴", Slot::FEET, 20, 20, 19, 596, 0, 0, 0, 0, 0, 1},
    {"征服者的胫甲", Slot::FEET, 21, 17, 23, 604, 4},
};
std::vector<Gear<int16_t>> fingers = {
    {"埃古雷亚指环", Slot::FINGER, 0, 16, 10, 0, 0, 0, 0, 0, 0, 2},
    {"迅击戒指", Slot::FINGER, 5, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 30},
    {"沉重的黑铁戒指", Slot::FINGER, 0, 0, 20, 110, 5},
    {"大金表", Slot::FINGER, 0, 14, 28, 0},
    {"屠龙大师之戒", Slot::FINGER, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 1, 48},
    {"源力之环", Slot::FINGER, 12, 22, 9, 0},
    {"坚定力量之戒", Slot::FINGER, 11, 0, 14, 0, 0, 0, 0, 0, 0, 0, 1},
    {"屠神者之戒", Slot::FINGER, 0, 27, 17, 0},
    {"维克洛尔大帝之戒", Slot::FINGER, 0, 12, 18, 100, 9},
    {"安格莉丝塔的触摸", Slot::FINGER, 11, 0, 17, 0, 6, 1},
    {"胡里奥指环", Slot::FINGER, 0, 0, 11, 0, 0, 0, 0, 0, 0, 1, 1, 16},
    // {"青铜龙防御戒指-中立", Slot::FINGER, 10, 0, 18, 0, 5},
    // {"青铜龙防御戒指-友善", Slot::FINGER, 11, 0, 19, 0, 5},
    // {"青铜龙防御戒指-尊敬", Slot::FINGER, 12, 0, 21, 0, 6},
    // {"青铜龙防御戒指-崇敬", Slot::FINGER, 12, 0, 22, 0, 6},
    // {"青铜龙防御戒指-崇拜", Slot::FINGER, 13, 0, 24, 0, 7},
    // {"青铜龙物理戒指-友善", Slot::FINGER, 0, 19, 9, 0, 0, 0, 0, 0, 0, 1},
    // {"青铜龙物理戒指-尊敬", Slot::FINGER, 0, 21, 11, 0, 0, 0, 0, 0, 0, 1},
    {"青铜龙物理戒指-崇敬", Slot::FINGER, 0, 22, 11, 0, 0, 0, 0, 0, 0, 1},
    // {"青铜龙物理戒指-崇拜", Slot::FINGER, 0, 24, 13, 0, 0, 0, 0, 0, 0, 1},
};
std::vector<Gear<int16_t>> trinckets = {
    {"黑手饰物", Slot::TRINCKET, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
    {"龙牙饰物", Slot::TRINCKET, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 56},
};
std::vector<Gear<int16_t>> rangeds = {
    {"龙息手持火炮", Slot::RANGED, 0, 14, 7, 0},
    {"末日迫近之弩", Slot::RANGED, 5, 7, 5, 0, 0, 0, 0, 0, 0, 1},
    {"哈霍兰之刺", Slot::RANGED, 0, 18, 0, 0},
};*/

int main() {
  /*GearCalculator<int16_t, float, uint8_t> calculator;
  calculator.SetGears(heads, necks, shoulders, backs, chests, wrists, hands,
                      waists, legs, feet, fingers, trinckets, rangeds);
  // calculator.SetWeight(
  //    2, // 力量
  //    3, // 敏捷
  //    3, // 耐力

  //)
  calculator.Calculate();*/
  return 0;
}
