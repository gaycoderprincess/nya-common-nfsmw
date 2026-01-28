#include <vector>

namespace NyaHooks {
	namespace OptionsMenuHook {
		class OMCustom : public IconOption {
		public:
			int optionId;

			OMCustom(uint32_t iconHash, uint32_t nameHash, int a3) : IconOption(iconHash, nameHash, a3) {}

			void React(const char* a1, uint32_t a2, FEObject* a3, uint32_t a4, uint32_t a5) override {
				if (a2 != 0xC407210) return;
				FEDatabase->CurrentUserProfiles[0]->TheOptionsSettings.CurrentCategory = (eOptionsCategory)optionId;
			}
		};

		class CustomOptionData {
		public:
			uint32_t iconHash;
			uint32_t nameHash;
			int optionId;

			OMCustom* CreateOption() {
				auto option = new OMCustom(iconHash, nameHash, 0);
				option->optionId = optionId;
				return option;
			}
		};
		std::vector<CustomOptionData> aMenuOptions;

		int AddInitFunc(void* initFunc) {
			auto options = (uintptr_t*)0x545DFC;
			for (int i = 0; i < 13; i++) {
				//if (options[i] == 0x545DEF || options[i] == 0xCCCCCCCC) {
				if (options[i] == 0xCCCCCCCC) {
					// change menu to init
					auto data = new uint8_t[0x12];
					memcpy(data, (void*)0x545DE8, 0x12);
					NyaHookLib::PatchRelative(NyaHookLib::CALL, (uintptr_t)(data + 2), initFunc);
					NyaHookLib::PatchRelative(NyaHookLib::CALL, (uintptr_t)(data + 0xB), 0x5A5EA0);
					NyaHookLib::Patch((uintptr_t)&options[i], data);
					NyaHookLib::Patch<uint8_t>(0x545D75 + 2, i); // switch case max

					// change fng to enter
					NyaHookLib::Patch(0x5456FC + (4 * i), 0x545642);
					NyaHookLib::Patch<uint8_t>(0x5455F1 + 2, i); // switch case max
					return i;
				}
			}
			return -1;
		}

		auto OptionsMenu_orig = (void(__thiscall*)(IconScrollerMenu*, IconOption*))nullptr;
		void __thiscall OptionsMenuHooked(IconScrollerMenu* pThis, IconOption* widget) {
			for (auto& option : aMenuOptions) {
				IconScrollerMenu::AddOption(pThis, option.CreateOption());
			}
			OptionsMenu_orig(pThis, widget);
		}

		void InitMenuHook() {
			static bool bOnce = false;
			if (bOnce) return;
			bOnce = true;

			OptionsMenu_orig = (void(__thiscall*)(IconScrollerMenu*, IconOption*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x528F8C, &OptionsMenuHooked);
			NyaHookLib::Patch<uint16_t>(0x51041A, 0x01B0); // default to options not changed to disable the exit prompt
		}

		// just using FEPrintf or somesuch to create a literal string seems to offset the text labels a bit, this seems to be the only way to make them look correct
		std::vector<StringRecord> aNewStringRecords;
		auto SearchForString_orig = (const char*(__fastcall*)(void*, uint32_t))nullptr;
		const char* __fastcall SearchForStringHooked(void* a1, uint32_t hash) {
			auto str = SearchForString_orig(a1, hash);
			if (!str) {
				for (auto& record : aNewStringRecords) {
					if (hash == record.Hash) return record.PackedString;
				}
			}
			return str;
		}

		void InitStringHook() {
			static bool bOnce = false;
			if (bOnce) return;
			bOnce = true;

			SearchForString_orig = (const char*(__fastcall*)(void*, uint32_t))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x57E924, &SearchForStringHooked);
		}

		std::vector<void(*)(UIWidgetMenu*)> aNewAudioOptions;
		auto AudioOptions1_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))nullptr;
		auto AudioOptions2_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))nullptr;
		void __thiscall AudioOptionsHooked1(UIWidgetMenu* pThis, FEToggleWidget* widget, bool a3) {
			AudioOptions1_orig(pThis, widget, a3);
			if (TheGameFlowManager.CurrentGameFlowState == GAMEFLOW_STATE_IN_FRONTEND) return;
			for (auto& func : aNewAudioOptions) {
				func(pThis);
			}
		}
		void __thiscall AudioOptionsHooked2(UIWidgetMenu* pThis, FEToggleWidget* widget, bool a3) {
			AudioOptions2_orig(pThis, widget, a3);
			for (auto& func : aNewAudioOptions) {
				func(pThis);
			}
		}

		std::vector<void(*)(UIWidgetMenu*)> aNewVideoOptions;
		auto VideoOptions_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))nullptr;
		void __thiscall VideoOptionsHooked(UIWidgetMenu* pThis, FEToggleWidget* widget, bool a3) {
			VideoOptions_orig(pThis, widget, a3);
			for (auto& func : aNewVideoOptions) {
				func(pThis);
			}
		}

		std::vector<void(*)(UIWidgetMenu*)> aNewGameplayOptions;
		auto GameplayOptions_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))nullptr;
		void __thiscall GameplayOptionsHooked(UIWidgetMenu* pThis, FEToggleWidget* widget, bool a3) {
			GameplayOptions_orig(pThis, widget, a3);
			for (auto& func : aNewGameplayOptions) {
				func(pThis);
			}
		}

		void InitAudioOptionsHook() {
			static bool bOnce = false;
			if (bOnce) return;
			bOnce = true;

			AudioOptions1_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x52954D, &AudioOptionsHooked1);
			AudioOptions2_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x529593, &AudioOptionsHooked2);
		}

		void InitVideoOptionsHook() {
			static bool bOnce = false;
			if (bOnce) return;
			bOnce = true;

			VideoOptions_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x529BC7, &VideoOptionsHooked);
		}

		void InitGameplayOptionsHook() {
			static bool bOnce = false;
			if (bOnce) return;
			bOnce = true;

			GameplayOptions_orig = (void(__thiscall*)(UIWidgetMenu*, FEToggleWidget*, bool))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x529E8D, &GameplayOptionsHooked);
		}

		bool AddNewMenu(void* initFunc, uint32_t iconHash, uint32_t nameHash) {
			auto id = AddInitFunc(initFunc);
			if (id < 0) return false;

			aMenuOptions.push_back({iconHash, nameHash, id});
			InitMenuHook();
			return true;
		}

		void AddMenuOption(eOptionsCategory category, void(*createFunction)(UIWidgetMenu*)) {
			switch (category) {
				case OC_AUDIO:
					aNewAudioOptions.push_back(createFunction);
					InitAudioOptionsHook();
					break;
				case OC_PC_ADV_DISPLAY:
					aNewVideoOptions.push_back(createFunction);
					InitVideoOptionsHook();
					break;
				case OC_GAMEPLAY:
					aNewGameplayOptions.push_back(createFunction);
					InitGameplayOptionsHook();
					break;
				// not implemented
				case OC_VIDEO:
				case OC_PLAYER:
				case OC_CONTROLS:
				case OC_ONLINE:
				default:
					break;
			}
		}

		void AddStringRecord(uint32_t hash, const char* str) {
			aNewStringRecords.push_back({hash, str});
			InitStringHook();
		}
	}

	namespace D3DEndSceneHook {
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)(void*))nullptr;
		void HookedFunction(void* a1) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1);
			for (auto& func : aFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E75A7, &HookedFunction);
		}
	}

	namespace D3DResetHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction();
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6DB0F9, &HookedFunction);
		}
	}

	namespace PreHUDDrawHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(__thiscall*)(void*))nullptr;
		void HookedFunction(void* a1) {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction(a1);
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E71D0, &HookedFunction);
		}
	}

	void PlaceD3DHooks(bool includePreHUD = false) {
		D3DEndSceneHook::Init();
		D3DResetHook::Init();
		if (includePreHUD) PreHUDDrawHook::Init();
	}

	namespace WorldServiceHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction();
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x663E5A, &HookedFunction);
		}
	}

	namespace InputBlockerHook {
		bool bInputsBlocked = false;
		
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (bool(*)())nullptr;
		bool HookedFunction() {
			if (bInputsBlocked) return true;
			return OrigFunction();
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (bool(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x645ECD, &HookedFunction);
		}
	}

	namespace WndProcHook {
		std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aFunctions;

		auto OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
		LRESULT __stdcall HookedFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			for (auto& func : aFunctions) {
				func(hWnd, msg, wParam, lParam);
			}
			return OrigFunction(hWnd, msg, wParam, lParam);
		}
		
		void Init() {
			if (OrigFunction) return;
			OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x6E6AF1);
			NyaHookLib::Patch(0x6E6AF1, &HookedFunction);
		}
	}

	namespace CameraHook {		
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			return OrigFunction();
		}
		
		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E736F, &HookedFunction);
		}
	}

	namespace CameraMoverHook {		
		std::vector<void(*)(CameraMover*)> aFunctions;

		auto OrigFunction = (void(__thiscall*)(CameraMover*, float))nullptr;
		void __thiscall HookedFunction(CameraMover* a1, float a2) {
			OrigFunction(a1, a2);
			for (auto& func : aFunctions) {
				func(a1);
			}
		}
		
		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(CameraMover*, float))(*(uintptr_t*)0x894CD0);
			NyaHookLib::Patch(0x894CD0, &HookedFunction);
		}
	}

	namespace LateInitHook {		
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)(int, char**))nullptr;
		void HookedFunction(int a1, char** a2) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1, a2);
			for (auto& func : aFunctions) {
				func();
			}
		}
		
		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)(int, char**))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6665B4, &HookedFunction);
		}
	}

	namespace LateInitHookAlternate {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)(int))nullptr;
		void HookedFunction(int a1) {
			OrigFunction(a1);
			for (auto& func : aFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)(int))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x66617F, &HookedFunction);
		}
	}

	namespace RenderWorldHook {		
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aPostFunctions;
		
		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction();
			for (auto& func : aPostFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			
			//0x6DED37
			//0x6DEEC6
			//0x6DF24E
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6DED37, &HookedFunction);
		}
	}

	namespace RenderPropsHook {
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aPostFunctions;
		
		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction();
			for (auto& func : aPostFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6DEDA0, &HookedFunction);
		}
	}

	namespace SimServiceHook {
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aPostFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction();
			for (auto& func : aPostFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x62539B, &HookedFunction);
		}
	}
}