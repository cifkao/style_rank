#ifndef STYLE_RANK_FEATURE_MAP_H
#define STYLE_RANK_FEATURE_MAP_H

#include "utils.hpp"

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

static unordered_map<string, unique_ptr<DISCRETE_DIST>(*)(Piece*)> m { 
    { "IntervalDist", &IntervalDist},
	{ "IntervalClassDist", &IntervalClassDist},
	{ "ChordSize", &ChordSize},
	{ "ChordPCSizeRatio", &ChordPCSizeRatio},
	{ "ChordOnsetRatio", &ChordOnsetRatio},
	{ "ChordDistinctDurationRatio", &ChordDistinctDurationRatio},
	{ "ChordDuration", &ChordDuration},
	{ "ChordShape", &ChordShape},
	{ "ChordOnsetShape", &ChordOnsetShape},
	{ "ChordPCD", &ChordPCD},
	{ "ChordPCDWBass", &ChordPCDWBass},
	{ "ChordOnsetPCD", &ChordOnsetPCD},
	{ "ChordOnsetTiePCD", &ChordOnsetTiePCD},
	{ "ChordOnsetTiePCDTogether", &ChordOnsetTiePCDTogether},
	{ "ChordTonnetz", &ChordTonnetz},
	{ "ChordOnset", &ChordOnset},
	{ "ChordRange", &ChordRange},
	{ "ChordDissonance", &ChordDissonance},
	{ "ChordTranDissonance", &ChordTranDissonance},
	{ "ChordLowestInterval", &ChordLowestInterval},
	{ "ChordSizeNgram", &ChordSizeNgram},
	{ "ChordTranVoiceMotion", &ChordTranVoiceMotion},
	{ "ChordTranRepeat", &ChordTranRepeat},
	{ "ChordTranScaleDistance", &ChordTranScaleDistance},
	{ "ChordTranScaleUnion", &ChordTranScaleUnion},
	{ "ChordTranDistance", &ChordTranDistance},
	{ "ChordTranOuter", &ChordTranOuter},
	{ "ChordTranBassInterval", &ChordTranBassInterval},
	{ "ChordTranMelodyInterval", &ChordTranMelodyInterval},
	{ "ChordMelodyNgram", &ChordMelodyNgram},
	{ "ChordSizeDurationWeighted", &ChordSizeDurationWeighted},
	{ "OffsetDistrubution", &OffsetDistrubution},
	{ "MelodicInterval", &MelodicInterval},
	{ "DurationDifference", &DurationDifference},
	{ "OnsetDifference", &OnsetDifference},
	{ "Onset", &Onset},
	{ "Duration", &Duration},
	{ "ChordOnsetDifference", &ChordOnsetDifference},
	{ "Pitch", &Pitch},
	{ "ChordOuterInterval", &ChordOuterInterval},
	{ "ChordDistance", &ChordDistance}
};

static unordered_map<string, vector<string>> feature_tag_map { 
    { "ORIGINAL", {"IntervalDist",
		"IntervalClassDist",
		"ChordSize",
		"ChordPCSizeRatio",
		"ChordOnsetRatio",
		"ChordDistinctDurationRatio",
		"ChordDuration",
		"ChordShape",
		"ChordOnsetShape",
		"ChordPCD",
		"ChordPCDWBass",
		"ChordOnsetPCD",
		"ChordOnsetTiePCD",
		"ChordOnsetTiePCDTogether",
		"ChordTonnetz",
		"ChordOnset",
		"ChordRange",
		"ChordDissonance",
		"ChordTranDissonance",
		"ChordLowestInterval",
		"ChordSizeNgram",
		"ChordTranVoiceMotion",
		"ChordTranRepeat",
		"ChordTranScaleDistance",
		"ChordTranScaleUnion",
		"ChordTranDistance",
		"ChordTranOuter",
		"ChordTranBassInterval",
		"ChordTranMelodyInterval",
		"ChordMelodyNgram"}},
	{ "MIREX", {"ChordSizeDurationWeighted",
		"OffsetDistrubution",
		"MelodicInterval",
		"DurationDifference",
		"OnsetDifference",
		"Onset",
		"Duration",
		"ChordOnsetDifference",
		"Pitch",
		"ChordOuterInterval",
		"ChordDistance"}}
};

#endif