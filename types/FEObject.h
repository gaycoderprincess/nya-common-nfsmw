class FEScript;
class FERenderObject;
class FEImage;
class FEngTextInputObject;
class FEPackage;
class FESliderWidget;

class FEWideString {
public:
	wchar_t* mpsString;
	unsigned long mulBufferLength;

	static inline auto Write = (int(__thiscall*)(FEWideString*, const char*))0x57E8C0;
};
static_assert(sizeof(FEWideString) == 0x8);

enum FEObjType {
	FE_None = 0,
	FE_Image = 1,
	FE_String = 2,
	FE_Model = 3,
	FE_List = 4,
	FE_Group = 5,
	FE_CodeList = 6,
	FE_Movie = 7,
	FE_Effect = 8,
	FE_ColoredImage = 9,
	FE_AnimImage = 10,
	FE_SimpleImage = 11,
	FE_MultiImage = 12,
	FE_UserMin = 256,
};

class FEMinNode {
public:
	FEMinNode* next;
	FEMinNode* prev;

	virtual void _vf0() {}
};
static_assert(sizeof(FEMinNode) == 0xC);

class FEMinList {
public:
	unsigned int numElements;
	FEMinNode* head;
	FEMinNode* tail;

	virtual void _vf0() {}
};
static_assert(sizeof(FEMinList) == 0x10);

class FEObject : public FEMinNode {
public:
	unsigned long GUID;
	unsigned long NameHash;
	char* pName;
	FEObjType Type;
	unsigned long Flags;
	unsigned short RenderContext;
	unsigned short ResourceIndex;
	unsigned long Handle;
	unsigned long UserParam;
	unsigned char* pData;
	unsigned long DataSize;
	FEMinList Responses;
	FEMinList Scripts;
	FEScript* pCurrentScript;
	FERenderObject* Cached;
};
static_assert(sizeof(FEObject) == 0x5C);

class FEString : public FEObject {
public:
	char* pLabelName;
	unsigned long LabelHash;
	FEWideString string;
	unsigned long Format;
	int Leading;
	unsigned long MaxWidth;
};
static_assert(sizeof(FEString) == 0x78);

class FEScrollBar {
public:
	uint8_t _0[0x5C];
	//bool bVertical;
	//bool bResizeHandle;
	//bool bHandleGrabbed;
	//bool bArrowsOnly;
	//bool bVisible;
	//bVector2 vGrabbedPos;
	//bVector2 vCurPos;
	//bVector2 vGrabOffset;
	//bVector2 vBackingPos;
	//bVector2 vBackingSize;
	//bVector2 vHandleMinSize;
	//float fSegSize;
	//Timer ScrollTime;
	//FEObject* pBacking;
	//FEObject* pHandle;
	//FEObject* pFirstArrow;
	//FEObject* pSecondArrow;
	//FEObject* pFirstBackingEnd;
	//FEObject* pSecondBackingEnd;
};
static_assert(sizeof(FEScrollBar) == 0x5C);

class FEWidget : public bTNode<FEWidget> {
public:
	bVector2 vTopLeft;
	bVector2 vSize;
	bVector2 vBackingOffset;
	FEObject* pBacking;
	bool bEnabled;
	bool bHidden;
	bool bMovedLastUpdate;

	virtual void* _dtor(bool) = 0;
};

class FEStatWidget : public FEWidget {
public:
	FEString* pTitle;
	FEString* pData;
	bVector2 vMaxTitleSize;
	bVector2 vMaxDataSize;
	bVector2 vDataPos;
};
static_assert(sizeof(FEStatWidget) == 0x4C);
static_assert(offsetof(FEStatWidget, pData) == 0x30);

struct ResultStat : public FEStatWidget {
public:
	FEString* Position;
	GRacerInfo* RacerInfo;
};
static_assert(sizeof(ResultStat) == 0x54);

class FEToggleWidget : public FEStatWidget {
public:
	void* operator new(size_t size) {
		return GAME_malloc(size);
	}

	FEImage* pLeftImage;
	FEImage* pRightImage;
	unsigned int EnableScript;
	unsigned int DisableScript;

	FEToggleWidget(bool state) {
		((FEToggleWidget*(__thiscall*)(FEToggleWidget*, bool))0x589300)(this, state);
	}

	virtual void* _dtor(bool a1) { return ((FEToggleWidget*(__thiscall*)(FEToggleWidget*, bool))0x528640)(this, a1); }
	virtual void Act(const char*, uint32_t) = 0;
	virtual void CheckMouse(const char* a1, float a2, float a3) { ((void(__thiscall*)(FEToggleWidget*, const char*, float, float))0x574540)(this, a1, a2, a3); }
	virtual void Draw() = 0;
	virtual void Position() { ((void(__thiscall*)(FEToggleWidget*))0x589390)(this); }
	virtual void Show() { ((void(__thiscall*)(FEToggleWidget*))0x5745B0)(this); }
	virtual void Hide() { ((void(__thiscall*)(FEToggleWidget*))0x5745F0)(this); }
	virtual void Enable() { ((void(__thiscall*)(FEToggleWidget*))0x589410)(this); }
	virtual void Disable() { ((void(__thiscall*)(FEToggleWidget*))0x589440)(this); }
	virtual void SetFocus(const char* a1) { ((void(__thiscall*)(FEToggleWidget*, const char*))0x574630)(this, a1); }
	virtual void UnsetFocus() { ((void(__thiscall*)(FEToggleWidget*))0x574660)(this); }
	virtual void SetPos(const bVector2* a1) { ((void(__thiscall*)(FEToggleWidget*, const bVector2*))0x51A6C0)(this, a1); }
	virtual void SetPosX(float a1) { ((void(__thiscall*)(FEToggleWidget*, float))0x574480)(this, a1); }
	virtual void SetPosY(float a1) { ((void(__thiscall*)(FEToggleWidget*, float))0x5744E0)(this, a1); }
	virtual void BlinkArrows(uint32_t a1) { ((void(__thiscall*)(FEToggleWidget*, uint32_t))0x574670)(this, a1); }
};
static_assert(sizeof(FEToggleWidget) == 0x5C);

class ScreenConstructorData {
public:
	const char* PackageFilename;
	FEPackage* pPackage;
	int Arg;
};

class MenuScreen {
public:
	bool mPlaySound;
	unsigned long mDirectionForNextSound;
	bool bEnableEAMessenger;
	const char* PackageFilename;
	ScreenConstructorData ConstructData;
	bool IsGarageScreen;
	FEngTextInputObject* TextInputObject;
	unsigned char mStartCapturingFromKeyboard;

	virtual void* _dtor(bool a1) = 0;
};
static_assert(sizeof(MenuScreen) == 0x2C);

class UIWidgetMenu : public MenuScreen {
public:
	bTList<FEWidget> Options;
	FEWidget* pCurrentOption;
	FEWidget* pViewTop;
	FEObject* pTitleMaster;
	FEObject* pDataMaster;
	FEObject* pPrevButtonObj;
	FEString* pDoneText;
	FEObject* pDone;
	FEObject* pCursor;
	FEScrollBar ScrollBar;
	const char* pTitleName;
	const char* pDataName;
	const char* pDataImageName;
	const char* pBackingName;
	const char* pLeftArrowName;
	const char* pRightArrowName;
	const char* pSliderName;
	bVector2 vWidgetStartPos;
	bVector2 vLastWidgetPos;
	bVector2 vWidgetSize;
	bVector2 vMaxTitleSize;
	bVector2 vMaxDataSize;
	bVector2 vDataPos;
	bVector2 vWidgetSpacing;
	unsigned int iIndexToAdd;
	unsigned int iLastSelectedIndex;
	unsigned int iMaxWidgetsOnScreen;
	unsigned int iPrevButtonMessage;
	unsigned int iPrevParam1;
	unsigned int iPrevParam2;
	bool bScrollWrapped;
	bool bCurrentOptionSet;
	bool bHasScrollBar;
	bool bViewNeedsSync;
	bool bAllowScroll;
	uint8_t _121[0x3];

	static inline auto AddToggleOption = (int(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))0x588570;
};
static_assert(sizeof(UIWidgetMenu) == 0x124);
static_assert(offsetof(UIWidgetMenu, ScrollBar) == 0x54);
static_assert(offsetof(UIWidgetMenu, pSliderName) == 0xC8);
static_assert(offsetof(UIWidgetMenu, bScrollWrapped) == 0x11C);

class IconOption : public bTNode<IconOption> {
public:
	void* operator new(size_t size) {
		return GAME_malloc(size);
	}

	unsigned int Item;
	FEObject* FEngObject;
	float XPos;
	float YPos;
	unsigned int OriginalColor;
	bool IsGreyOut;
	bool IsFlashable;
	bool Locked;
	float OrigWidth;
	float OrigHeight;
	unsigned int NameHash;
	unsigned int DescHash;
	float fScaleToPcnt;
	float fScaleStartSecs;
	float fScaleDurSecs;
	float fScaleAtStart;
	bool bAnimComplete;
	bool bReactImmediately;
	bool bIsTutorialAvailable;
	const char* pTutorialMovieName;

	IconOption(uint32_t iconHash, uint32_t nameHash, int a3) {
		((IconOption*(__thiscall*)(IconOption*, uint32_t, uint32_t, int))0x586FA0)(this, iconHash, nameHash, a3);
	}

	virtual void* _dtor(bool a1) { return ((IconOption*(__thiscall*)(IconOption*, bool))0x51A500)(this, a1); }
	virtual void React(const char* a1, uint32_t a2, FEObject* a3, uint32_t a4, uint32_t a5) = 0;
};
static_assert(sizeof(IconOption) == 0x4C);

class IconScrollerMenu {
public:
	static inline auto AddOption = (int(__thiscall*)(IconScrollerMenu*, IconOption*))0x573960;
};

class UIOptionsScreen : public UIWidgetMenu {
public:
	struct GraphicsOptions {
		uint8_t _0[0x2C];
		int g_MotionBlurEnable; // +2C
		uint8_t _30[0x3C];
		int g_RacingResolution; // +6C
	};

	bool mCalledFromPauseMenu;
	bool NeedsColorCal;
	bool mInitialAutoSaveValue;
	FEToggleWidget* speakeroption;
	FESliderWidget* volumeoption;
	AudioSettings* OriginalAudioSettings;
	VideoSettings* OriginalVideoSettings;
	GameplaySettings* OriginalGameplaySettings;
	PlayerSettings* OriginalPlayerSettings;

	static inline auto& OptionsToEdit = *(GraphicsOptions***)0x91CA20;
};
//static_assert(sizeof(UIOptionsScreen) == 0x158);
static_assert(offsetof(UIOptionsScreen, mCalledFromPauseMenu) == 0x124);

auto FEPrintf = (int(*)(FEString*, const char*, ...))0x515D70;
void FEngSetLanguageHash(const char* a1, uint32_t a2, uint32_t a3) {
	auto tmp = (void(*)(const char*, uint32_t, uint32_t))0x525220;
	return tmp(a1, a2, a3);
}
void FEngSetLanguageHash(FEString* a1, uint32_t a2) {
	auto tmp = (void(*)(FEString*, uint32_t))0x515C00;
	return tmp(a1, a2);
}

class UIQRChallengeSeries;
class UIQRMainMenu;
auto CreateQRChallengeSeries = (UIQRChallengeSeries*(*)(ScreenConstructorData*))0x570CC0;