class FEWideString {
public:
	wchar_t* mpsString;
	unsigned long mulBufferLength;

	static inline auto Write = (int(__thiscall*)(FEWideString*, const char*))0x57E8C0;
};
static_assert(sizeof(FEWideString) == 0x8);

class FEScript;
class FERenderObject;

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

class FEImage;
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

class FEToggleWidget : public FEStatWidget {
public:
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

class UIWidgetMenu {
public:
	static inline auto AddToggleOption = (int(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))0x588570;
};

class UIOptionsScreen {
public:
	struct Options {
		uint8_t _0[0x2C];
		int g_MotionBlurEnable; // +2C
		uint8_t _30[0x3C];
		int g_RacingResolution; // +6C
	};

	static inline auto& OptionsToEdit = *(Options***)0x91CA20;
};

auto FEPrintf = (int(*)(FEString*, const char*, ...))0x515D70;