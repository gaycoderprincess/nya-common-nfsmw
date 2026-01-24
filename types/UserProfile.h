enum eControllerConfig {
	MIN_CONFIG = 0,
	CC_CONFIG_1 = 0,
	CC_CONFIG_2 = 1,
	CC_CONFIG_3 = 2,
	CC_CONFIG_4 = 3,
	MAX_CONFIG = 4,
	CC_CONFIG_5 = 4,
	NUM_CONTROLLER_CONFIGS = 5,
};

enum ePlayerSettingsCameras {
	PSC_BUMPER = 0,
	PSC_HOOD = 1,
	PSC_DEFAULT = 2,
	PSC_CLOSE = 2,
	PSC_FAR = 3,
	PSC_SUPER_FAR = 4,
	PSC_DRIFT = 5,
	PSC_PURSUIT = 6,
	NUM_CAMERAS_IN_OPTIONS = 7,
};

struct PlayerSettings {
	bool GaugesOn;
	bool PositionOn;
	bool LapInfoOn;
	bool ScoreOn;
	bool Rumble;
	bool LeaderboardOn;
	bool TransmissionPromptOn;
	bool DriveWithAnalog;
	eControllerConfig Config;
	ePlayerSettingsCameras CurCam;
	unsigned char SplitTimeType;
	unsigned char Transmission;
	unsigned char Handling;
};

struct GameplaySettings {
	bool AutoSaveOn;
	bool RearviewOn;
	bool Damage;
	unsigned char SpeedoUnits;
	unsigned char RacingMiniMapMode;
	unsigned char ExploringMiniMapMode;
	unsigned int MapItems;
	unsigned char LastMapZoom;
	unsigned char LastPursuitMapZoom;
	unsigned char LastMapView;
	bool JumpCam;
	float HighlightCam;
};

struct VideoSettings {
	float FEScale;
	float ScreenOffsetX;
	float ScreenOffsetY;
	bool WideScreen;
};

struct AudioSettings {
	float MasterVol;
	float SpeechVol;
	float FEMusicVol;
	float IGMusicVol;
	float SoundEffectsVol;
	float EngineVol;
	float CarVol;
	float AmbientVol;
	float SpeedVol;
	int AudioMode;
	int InteractiveMusicMode;
	int EATraxMode;
	int PlayState;
};

enum eOptionsCategory {
	OC_AUDIO = 0,
	OC_VIDEO = 1,
	OC_PC_ADV_DISPLAY = 2,
	OC_GAMEPLAY = 3,
	OC_PLAYER = 4,
	OC_CONTROLS = 5,
	OC_EATRAX = 6,
	OC_TRAILERS = 7,
	OC_CREDITS = 8,
	OC_ONLINE = 9,
	NUM_OPTIONS_CATEGORIES = 10,
};

class OptionsSettings {
public:
	eOptionsCategory CurrentCategory;
	VideoSettings TheVideoSettings;
	GameplaySettings TheGameplaySettings;
	AudioSettings TheAudioSettings;
	PlayerSettings ThePlayerSettings[2];
};

struct SMSMessage {
	unsigned char Handle;
	unsigned char Flags;
	unsigned short SortOrder;
};

class CareerSettings {
public:
	unsigned int CurrentCar;
	unsigned int SpecialFlags;
	unsigned char CurrentBin;
	int CurrentCash;
	short AdaptiveDifficulty;
	SMSMessage SMSMessages[150];
	unsigned short SMSSortOrder;
	char CaseFileName[16];
};

struct JukeboxEntry {
	unsigned int SongIndex;
	unsigned char PlayabilityField;
};

class UserProfile {
public:
	char m_aProfileName[32];
	bool m_bNamed;
	OptionsSettings TheOptionsSettings;
	CareerSettings TheCareerSettings;
	JukeboxEntry Playlist[30];
	FEPlayerCarDB PlayersCarStable; // +414
};
static_assert(sizeof(UserProfile) == 0x414+sizeof(FEPlayerCarDB));

class cFrontendDatabase {
public:
	uint8_t _0[0x10];
	UserProfile* mUserProfile; // +10

	static inline auto IsFinalEpicChase = (bool(__thiscall*)(cFrontendDatabase*))0x56DC00;
	static inline auto GetRaceNameHash = (uint32_t(__thiscall*)(cFrontendDatabase*, int))0x56E010;
	static inline auto GetRaceIconHash = (uint32_t(__thiscall*)(cFrontendDatabase*, int))0x56E090;
	static inline auto GetMilestoneIconHash = (uint32_t(__thiscall*)(cFrontendDatabase*, int, bool))0x56DEA0;
};
auto& FEDatabase = *(cFrontendDatabase**)0x91CF90;