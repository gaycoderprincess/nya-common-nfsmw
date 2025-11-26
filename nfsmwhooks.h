#include <vector>

namespace NyaHooks {
	std::vector<void(*)()> aEndSceneFuncs;
	std::vector<void(*)()> aD3DResetFuncs;
	std::vector<void(*)()> aPreHUDDrawFuncs;
	std::vector<void(*)()> aWorldServiceFuncs;
	std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aWndProcFuncs;
	bool bInputsBlocked = false;

	auto EndSceneOrig = (void(__cdecl*)(void*))nullptr;
	void __cdecl EndSceneHook(void* a1) {
		EndSceneOrig(a1);
		for (auto& func : aEndSceneFuncs) {
			func();
		}
	}

	auto PreHUDDrawOrig = (void(__thiscall*)(void*))nullptr;
	void __cdecl PreHUDDrawHook(void* a1) {
		for (auto& func : aPreHUDDrawFuncs) {
			func();
		}
		PreHUDDrawOrig(a1);
	}

	auto D3DResetOrig = (void(*)())nullptr;
	void D3DResetHook() {
		for (auto& func : aD3DResetFuncs) {
			func();
		}
		return D3DResetOrig();
	}

	auto WorldServiceOrig = (void(__cdecl*)())nullptr;
	void WorldServiceHook() {
		for (auto& func : aWorldServiceFuncs) {
			func();
		}
		return WorldServiceOrig();
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

	void PlaceD3DHooks(bool includePreHUD = false) {
		if (!EndSceneOrig) {
			EndSceneOrig = (void(__cdecl*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E75A7, &EndSceneHook);
			if (includePreHUD) PreHUDDrawOrig = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E71D0, &PreHUDDrawHook);
			D3DResetOrig = (void(__cdecl*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6E7606, &D3DResetHook);
		}
	}

	void PlaceWorldServiceHook() {
		if (!WorldServiceOrig) {
			WorldServiceOrig = (void(__cdecl*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x663E5A, &WorldServiceHook);
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