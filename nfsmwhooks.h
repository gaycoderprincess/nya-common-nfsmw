#include <vector>

namespace NyaHooks {
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
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x62539B, &HookedFunction);
		}
	}
}