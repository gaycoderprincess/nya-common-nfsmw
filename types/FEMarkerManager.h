class FEMarkerManager {
public:
	enum ePossibleMarker {
		MARKER_NONE = 0,
		MARKER_FIRST = 1,
		MARKER_CUSTOMIZE_FIRST = 1,
		MARKER_BRAKES = 1,
		MARKER_ENGINE = 2,
		MARKER_NITROUS = 3,
		MARKER_SUPERCHARGER = 4,
		MARKER_SUSPENSION = 5,
		MARKER_TIRES = 6,
		MARKER_TRANSMISSION = 7,
		MARKER_BODY = 8,
		MARKER_HOOD = 9,
		MARKER_SPOILER = 10,
		MARKER_RIMS = 11,
		MARKER_ROOF_SCOOP = 12,
		MARKER_VINYL = 13,
		MARKER_DECAL = 14,
		MARKER_PAINT = 15,
		MARKER_CUSTOM_HUD = 16,
		MARKER_CUSTOMIZE_LAST = 16,
		MARKER_GET_OUT_OF_JAIL = 17,
		MARKER_PINK_SLIP = 18,
		MARKER_CASH = 19,
		MARKER_ADD_IMPOUND_BOX = 20,
		MARKER_IMPOUND = 21,
	};

	struct SelectableMarker {
		uint32_t MarkerType;
		uint32_t param1;
		uint32_t param2;
	};

	SelectableMarker mPlayersMarkers[64];

	static inline auto AddMarkerToInventory = (void(__thiscall*)(FEMarkerManager*, uint32_t marker, uint32_t param1))0x576C50;
	static inline auto UtilizeMarker = (int(__thiscall*)(FEMarkerManager*, uint32_t marker, uint32_t param1))0x576C90;
	static inline auto GetNumMarkers = (int(__thiscall*)(FEMarkerManager*, uint32_t marker, uint32_t param1))0x576F10;
};

auto& TheFEMarkerManager = *(FEMarkerManager*)0x91D928;