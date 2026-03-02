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
static_assert(offsetof(UserProfile, TheOptionsSettings.CurrentCategory) == 0x24);

enum eLoadSaveGame {
	eLOADSAVE_LOAD = 0,
	eLOADSAVE_SAVE = 1,
};

struct RaceSettings {
	unsigned int EventHash;
	unsigned char NumLaps;
	unsigned char TrackDirection;
	bool IsLapKO;
	unsigned char NumOpponents;
	unsigned char AISkill;
	unsigned char CopDensity;
	unsigned char TrafficDensity;
	bool CatchUp;
	bool CopsOn;
	unsigned char RegionFilterBits;
	unsigned int SelectedCar[2];
};

struct FEKeyboardSettings {
	int AcceptCallbackHash;
	int DeclineCallbackHash;
	int DefaultTextHash;
	int MaxTextLength;
	int Mode;
	char Buffer[156];
	char Title[156];
};

struct FinishedRaceStatsEntry {
	struct Timer {
		int PackedTime;
	};

	int FinishPosition;
	int DriverNumber;
	int FinishReason;
	Timer RaceTime;
	Timer BestLapTime;
	int HandlingMode;
	float TopSpeed;
	float AverageSpeed;
	Timer LapTimes[11];
	Timer LapRunningTimes[11];
	int NumLapsCompleted;
	float NumLapsCompletedExact;
	int PositionPerLap[8];
	int NumLapsLead;
	float Odometer;
	Timer ZeroToSixtyTime;
	Timer QuarterMileTime;
	float QuarterMileSpeed;
	float LongestJump;
	float LongestPowerSlide;
	int WasRecordBreaker;
};
static_assert(sizeof(FinishedRaceStatsEntry) == 0xC0);

struct cFinishedRaceStats {
	FinishedRaceStatsEntry RaceStats[8];
	int NumStats;
};

enum ePostRaceOptions {
	POST_RACE_OPT_NEXT_RACE = 0,
	POST_RACE_OPT_QUIT = 1,
	POST_RACE_OPT_RESTART_RACE = 2,
	POST_RACE_OPT_RESTART_EVENT = 3,
};

enum eFEGameModes {
	eFE_GAME_MODE_NONE = 0,
	eFE_GAME_MODE_CAREER = 1,
	eFE_GAME_MODE_CHALLENGE = 2,
	eFE_GAME_MODE_QUICK_RACE = 4,
	eFE_GAME_MODE_ONLINE = 8,
	eFE_GAME_MODE_OPTIONS = 16,
	eFE_GAME_MODE_CUSTOMIZE = 32,
	eFE_GAME_MODE_LAN = 64,
	eFE_GAME_MODE_PROFILE_MANAGER = 128,
	eFE_GAME_MODE_CAREER_MANAGER = 256,
	eFE_GAME_MODE_RAP_SHEET = 512,
	eFE_GAME_MODE_MODE_SELECT = 1024,
	eFE_GAME_TRAILERS = 2048,
	eFE_GAME_MODE_CAR_LOT = 32768,
	eFE_GAME_MODE_SAFEHOUSE = 65536,
	eFE_GAME_MODE_POST_RIVAL = 131072,
	eFE_GAME_MODE_BEAT_GAME = 262144,
	eFE_GAME_MODE_ALL = 4294967295,
};

class cFrontendDatabase {
public:
	unsigned char iNumPlayers;
	bool bComingFromBoot;
	bool bSavedProfileForMP;
	bool bProfileLoaded;
	bool bIsOptionsDirty;
	bool bAutoSaveOverwriteConfirmed;
	unsigned int iDefaultStableHash;
	signed char PlayerJoyports[2];
	UserProfile* CurrentUserProfiles[2];
	GRace::Type RaceMode;
	RaceSettings TheQuickRaceSettings[11];
	char* m_pCarStableBackup;
	char* m_pDBBackup;
	unsigned int FEGameMode;
	eLoadSaveGame LoadSaveGame;
	FEKeyboardSettings mFEKeyboardSettings;
	int iCurPauseSubOptionType;
	int iCurPauseOptionType;
	FECustomizationRecord* SplitScreenCustomization;
	char SplitScreenCarType[256];
	cFinishedRaceStats FinishedRaceStats;
	ePostRaceOptions PostRaceOptionChosen;

	static inline auto IsFinalEpicChase = (bool(__thiscall*)(cFrontendDatabase*))0x56DC00;
	static inline auto GetRaceNameHash = (uint32_t(__thiscall*)(cFrontendDatabase*, int))0x56E010;
	static inline auto GetRaceIconHash = (uint32_t(__thiscall*)(cFrontendDatabase*, int))0x56E090;
	static inline auto GetMilestoneIconHash = (uint32_t(__thiscall*)(cFrontendDatabase*, int, bool))0x56DEA0;
};
static_assert(offsetof(cFrontendDatabase, CurrentUserProfiles[0]) == 0x10);
static_assert(offsetof(cFrontendDatabase, FEGameMode) == 0x12C);

auto& FEDatabase = *(cFrontendDatabase**)0x91CF90;