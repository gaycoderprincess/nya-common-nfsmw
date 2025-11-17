#include <vector>

namespace NyaHooks {
	std::vector<void(*)()> aEndSceneFuncs;
	std::vector<void(*)()> aD3DResetFuncs;
	std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aWndProcFuncs;
	bool bInputsBlocked = false;

	auto EndSceneOrig = (void(__cdecl*)(void*))nullptr;
	void __cdecl EndSceneHook(void* a1) {
		EndSceneOrig(a1);
		for (auto& func : aEndSceneFuncs) {
			func();
		}
	}

	auto D3DResetOrig = (void(*)())nullptr;
	void D3DResetHook() {
		for (auto& func : aD3DResetFuncs) {
			func();
		}
		return D3DResetOrig();
	}

	auto InputBlockerOrig = (bool(__cdecl*)())nullptr;
	bool InputBlockerHook() {
		if (bInputsBlocked) return true;
		return InputBlockerOrig();
	}

	auto WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
	LRESULT __stdcall WndProcHook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		for (auto& func : aWndProcFuncs) {
			func(hWnd, msg, wParam, lParam);
		}
		return WndProcOrig(hWnd, msg, wParam, lParam);
	}

	void PlaceD3DHooks() {
		if (!EndSceneOrig) {
			EndSceneOrig = (void(__cdecl*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E75A7, &EndSceneHook);
			D3DResetOrig = (void(__cdecl*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E7606, &D3DResetHook);
		}
	}

	void PlaceInputBlockerHook() {
		if (!InputBlockerOrig) {
			InputBlockerOrig = (bool(__cdecl*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x645ECD, &InputBlockerHook);
		}
	}

	void PlaceWndProcHook() {
		if (!WndProcOrig) {
			WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x6E6AF1);
			NyaHookLib::Patch(0x6E6AF1, &WndProcHook);
		}
	}
}