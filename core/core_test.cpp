#include "core.h"

#include <cstdint>
#include <iostream>

std::vector<Gear<int16_t>> heads = {
    Gear<int16_t>("�����ߵĻʹ�", Slot::HEAD, 29, 18, 34, 739, 6),
    //{"�޾�ŭ��ͷ��", Slot::HEAD, 26, 26, 29, 679},
}; /*
std::vector<Gear<int16_t>> necks = {
    {"������ʦѫ��", Slot::NECK, 0, 14, 24, 0, 7},
    {"���ն���ӡ��", Slot::NECK, 0, 0, 24, 0, 10, 1, 0, 0, 0, 1},
    {"���ݿ�ϣ������׹��", Slot::NECK, 0, 12, 9, 0, 0, 0, 0, 0, 0, 1, 1},
};
std::vector<Gear<int16_t>> shoulders = {
    {"�����ߵļ���", Slot::SHOULDER, 20, 16, 21, 659, 4, 0, 0, 0, 0, 1},
    {"��ŭ����", Slot::SHOULDER, 13, 0, 27, 642, 7, 0, 0, 0, 27},
    {"��צ����", Slot::SHOULDER, 20, 20, 17, 634, 0, 1},
};
std::vector<Gear<int16_t>> backs = {
    {"������������", Slot::BACK, 11, 26, 15, 66},
    {"Դ��˿������", Slot::BACK, 0, 0, 13, 169, 0, 2},
    {"�ᶨ��������", Slot::BACK, 15, 9, 9, 52, 0, 0, 0, 0, 0, 1},
    {"ɳĮ�籩����", Slot::BACK, 12, 0, 12, 135, 6, 1},
    {"������", Slot::BACK, 13, 10, 19, 59, 6},
};
std::vector<Gear<int16_t>> chests = {
    {"�����ߵ��ؼ�", Slot::CHEST, 34, 24, 38, 985, 6},
};
std::vector<Gear<int16_t>> wrists = {
    {"��ŭ����", Slot::WRIST, 13, 0, 27, 375},
    {"Ұ������", Slot::WRIST, 21, 12, 9, 356},
};
std::vector<Gear<int16_t>> hands = {
    {"������", Slot::HAND, 35, 0, 15, 615, 0, 0, 0, 0, 0, 1, 1},
    {"��ŭ����", Slot::HAND, 15, 0, 20, 535, 7, 0, 1},
    {"������������", Slot::HAND, 0, 0, 13, 488, 0, 0, 0, 0, 0, 0, 1, 54},
    {"�ᶨ�����", Slot::HAND, 19, 18, 20, 535, 9},
};
std::vector<Gear<int16_t>> waists = {
    {"�ʼ���������", Slot::WAIST, 13, 13, 22, 512, 8, 0, 1},
    {"�������", Slot::WAIST, 31, 0, 11, 494, 0, 0, 0, 0, 0, 1, 1},
    {"��������", Slot::WAIST, 26, 19, 17, 476},
};
std::vector<Gear<int16_t>> legs = {
    {"�����ߵ�����", Slot::LEG, 33, 21, 24, 796, 6, 0, 0, 0, 0, 1},
    {"��ŭ����", Slot::LEG, 19, 0, 27, 749, 11, 2},
};
std::vector<Gear<int16_t>> feet = {
    {"��ŭ��ѥ", Slot::FEET, 13, 0, 30, 589, 7, 0, 0, 0, 14},
    {"��ʳ�ѥ", Slot::FEET, 20, 20, 19, 596, 0, 0, 0, 0, 0, 1},
    {"�����ߵ��ּ�", Slot::FEET, 21, 17, 23, 604, 4},
};
std::vector<Gear<int16_t>> fingers = {
    {"��������ָ��", Slot::FINGER, 0, 16, 10, 0, 0, 0, 0, 0, 0, 2},
    {"Ѹ����ָ", Slot::FINGER, 5, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 30},
    {"���صĺ�����ָ", Slot::FINGER, 0, 0, 20, 110, 5},
    {"����", Slot::FINGER, 0, 14, 28, 0},
    {"������ʦ֮��", Slot::FINGER, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 1, 48},
    {"Դ��֮��", Slot::FINGER, 12, 22, 9, 0},
    {"�ᶨ����֮��", Slot::FINGER, 11, 0, 14, 0, 0, 0, 0, 0, 0, 0, 1},
    {"������֮��", Slot::FINGER, 0, 27, 17, 0},
    {"ά��������֮��", Slot::FINGER, 0, 12, 18, 100, 9},
    {"������˿���Ĵ���", Slot::FINGER, 11, 0, 17, 0, 6, 1},
    {"�����ָ��", Slot::FINGER, 0, 0, 11, 0, 0, 0, 0, 0, 0, 1, 1, 16},
    // {"��ͭ��������ָ-����", Slot::FINGER, 10, 0, 18, 0, 5},
    // {"��ͭ��������ָ-����", Slot::FINGER, 11, 0, 19, 0, 5},
    // {"��ͭ��������ָ-��", Slot::FINGER, 12, 0, 21, 0, 6},
    // {"��ͭ��������ָ-�羴", Slot::FINGER, 12, 0, 22, 0, 6},
    // {"��ͭ��������ָ-���", Slot::FINGER, 13, 0, 24, 0, 7},
    // {"��ͭ�������ָ-����", Slot::FINGER, 0, 19, 9, 0, 0, 0, 0, 0, 0, 1},
    // {"��ͭ�������ָ-��", Slot::FINGER, 0, 21, 11, 0, 0, 0, 0, 0, 0, 1},
    {"��ͭ�������ָ-�羴", Slot::FINGER, 0, 22, 11, 0, 0, 0, 0, 0, 0, 1},
    // {"��ͭ�������ָ-���", Slot::FINGER, 0, 24, 13, 0, 0, 0, 0, 0, 0, 1},
};
std::vector<Gear<int16_t>> trinckets = {
    {"��������", Slot::TRINCKET, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
    {"��������", Slot::TRINCKET, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 56},
};
std::vector<Gear<int16_t>> rangeds = {
    {"��Ϣ�ֳֻ���", Slot::RANGED, 0, 14, 7, 0},
    {"ĩ���Ƚ�֮��", Slot::RANGED, 5, 7, 5, 0, 0, 0, 0, 0, 0, 1},
    {"������֮��", Slot::RANGED, 0, 18, 0, 0},
};*/

int main() {
  /*GearCalculator<int16_t, float, uint8_t> calculator;
  calculator.SetGears(heads, necks, shoulders, backs, chests, wrists, hands,
                      waists, legs, feet, fingers, trinckets, rangeds);
  // calculator.SetWeight(
  //    2, // ����
  //    3, // ����
  //    3, // ����

  //)
  calculator.Calculate();*/
  return 0;
}
