class GrandSceneryCullInfo {
public:
	static inline auto StuffScenery = (void(__thiscall*)(GrandSceneryCullInfo*, eView*, int))0x723FA0;
};

auto RenderVisibleZones = (void(__cdecl*)(eView*))0x72DFB0;
auto& ShowSectionBoarder = *(bool*)0x9A3A50;

class SceneryGroup : public bTNode<SceneryGroup> {
public:
	unsigned int NameHash;
	short GroupNumber;
	short NumObjects;
	char BarrierFlag;
	char DriveThroughBarrierFlag;
	short Pad2;
	unsigned short OverrideInfoNumbers[16384];
};
static_assert(sizeof(SceneryGroup) == 0x8014);
static_assert(offsetof(SceneryGroup, NameHash) == 0x8);
auto& SceneryGroupList = *(bList<SceneryGroup>*)0x9AB24C;

auto EnableBarrierSceneryGroup = (void(*)(int, bool))0x64B410;
auto EnableSceneryGroup = (void(*)(int, bool))0x72C5C0;
auto DisableSceneryGroup = (void(*)(int))0x72C620;
auto SceneryGroupEnabledTable = (uint8_t*)0x902160; // [4096]