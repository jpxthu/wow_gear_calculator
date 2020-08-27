#include "core.h"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> Split(const std::string& s, char c) {
  std::vector<std::string> ss;
  size_t i = 0, j = 0;
  while (true) {
    j = s.find_first_of(c, i);
    ss.push_back(s.substr(i, j - i));
    i = j + 1;
    if (i == 0) {
      return ss;
    }
  }
}

StatT StringToStat(const std::string& s) {
  return s.empty() ? StatT(0) : StatT(std::stoi(s));
}

bool LoadGears(std::ifstream& ifs, Slot slot, std::vector<Gear>* gears) {
  std::string line;
  if (!std::getline(ifs, line)) {
    return false;
  }

  while (std::getline(ifs, line)) {
    if (line.empty() || line[0] == '-') {
      break;
    }
    if (line[0] == '0') {
      continue;
    }
    const std::vector<std::string>& ss = Split(line, ',');
    Gear gear =
        Gear(ss[1], slot, StringToStat(ss[2]), StringToStat(ss[3]),
             StringToStat(ss[4]), StringToStat(ss[5]), StringToStat(ss[6]),
             StringToStat(ss[7]), StringToStat(ss[8]), StringToStat(ss[9]),
             StringToStat(ss[10]), StringToStat(ss[11]), StringToStat(ss[12]),
             StringToStat(ss[13]), StringToSets(ss[14]));
    gears->push_back(gear);
  }

  return true;
}

bool LoadWeight(std::ifstream& ifs, StatWeight* weight, WeightT* bonus) {
  std::string line;
  while (std::getline(ifs, line)) {
    if (line.empty() || line[0] == '-') {
      break;
    }
    const std::vector<std::string>& ss = Split(line, ',');
    const std::string& type = ss[0];
    WeightT v = ss[2].empty() ? WeightT(0) : WeightT(std::stod(ss[2]));
    if (type == "STRENGTH") {
      weight->stats[STRENGTH] = v;
    } else if (type == "AGILITY") {
      weight->stats[AGILITY] = v;
    } else if (type == "STAMINA") {
      weight->stats[STAMINA] = v;
    } else if (type == "ARMOR") {
      weight->stats[ARMOR] = v;
    } else if (type == "DEFENCE") {
      weight->stats[DEFENCE] = v;
    } else if (type == "DODGE") {
      weight->stats[DODGE] = v;
    } else if (type == "PARRY") {
      weight->stats[PARRY] = v;
    } else if (type == "BLOCK") {
      weight->stats[BLOCK] = v;
    } else if (type == "BLOCK_V") {
      weight->stats[BLOCK_VALUE] = v;
    } else if (type == "CRIT") {
      weight->stats[CRIT] = v;
    } else if (type == "AP") {
      weight->stats[ATTACK_POWER] = v;
    } else if (type == "HIT") {
      weight->stats[HIT] = v;
    } else if (type == "HIT_2") {
      weight->hit_over_threshold = v;
    } else if (type == "HIT_THRES") {
      weight->hit_threshold =
          ss[2].empty() ? StatT(0) : StatT(std::stoi(ss[2]));
    } else if (type == "BONUS") {
      *bonus = v;
    }
  }
  return true;
}

bool LoadSets(std::ifstream& ifs, std::vector<SetBonus>* set_bonuses) {
  for (int i = 0; i < SET_NONE; i++) {
    set_bonuses[i].clear();
  }

  std::string line;
  while (std::getline(ifs, line)) {
    if (line.empty() || line[0] == '-') {
      break;;
    }
    const std::vector<std::string>& ss = Split(line, ',');
    GearSet set;
    if (ss[0] == "T2") {
      set = T2;
    } else if (ss[0] == "T2.5") {
      set = T2_5;
    } else if (ss[0] == "T3") {
      set = T3;
    } else {
      continue;
    }

    set_bonuses[set].push_back(SetBonus{uint8_t(std::stoi(ss[1])),
                                        WeightT(std::stof(ss[2]))});
  }

  return true;
}

int main() {
  std::vector<Gear> gears[SLOT_NUM]{};
  StatWeight weight{};
  WeightT bonus = WeightT(0);
  std::vector<SetBonus> set_bonuses[SET_NONE];

  std::ifstream ifs("settings.csv");
  std::string line;

  while (std::getline(ifs, line)) {
    const std::vector<std::string>& ss = Split(line, ',');
    const std::string& type = ss[2];
    if (type.empty()) {
      continue;
    } else if (type.compare("HEAD") == 0) {
      LoadGears(ifs, HEAD, &gears[HEAD]);
    } else if (type.compare("NECK") == 0) {
      LoadGears(ifs, NECK, &gears[NECK]);
    } else if (type.compare("SHOULDER") == 0) {
      LoadGears(ifs, SHOULDER, &gears[SHOULDER]);
    } else if (type.compare("BACK") == 0) {
      LoadGears(ifs, BACK, &gears[BACK]);
    } else if (type.compare("CHEST") == 0) {
      LoadGears(ifs, CHEST, &gears[CHEST]);
    } else if (type.compare("WRIST") == 0) {
      LoadGears(ifs, WRIST, &gears[WRIST]);
    } else if (type.compare("HAND") == 0) {
      LoadGears(ifs, HAND, &gears[HAND]);
    } else if (type.compare("WAIST") == 0) {
      LoadGears(ifs, WAIST, &gears[WAIST]);
    } else if (type.compare("LEG") == 0) {
      LoadGears(ifs, LEG, &gears[LEG]);
    } else if (type.compare("FEET") == 0) {
      LoadGears(ifs, FEET, &gears[FEET]);
    } else if (type.compare("TRINKET") == 0) {
      LoadGears(ifs, TRINKET, &gears[TRINKET]);
    } else if (type.compare("RANGED") == 0) {
      LoadGears(ifs, RANGED, &gears[RANGED]);
    } else if (type.compare("FINGER") == 0) {
      LoadGears(ifs, FINGER, &gears[FINGER]);
    } else if (type.compare("WEIGHT") == 0) {
      LoadWeight(ifs, &weight, &bonus);
    } else if (type.compare("SET") == 0) {
      LoadSets(ifs, set_bonuses);
    }
  }

  GearCalculator calculator;
  calculator.SetGears(gears);
  calculator.SetWeight(weight, bonus);
  calculator.SetSetBonuses(set_bonuses);
  calculator.Calculate();
  calculator.OutputResult("result.csv");
  return 0;
}
