#pragma once

namespace WndFunc
{
	LRESULT CALLBACK KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam);
	string GetForgroundProcessName();
	void UpdateList();
	bool LoadDataPath();
	void SaveDataPath();
	int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
	bool AddItem(char *Name,int Item, int SubItem, ItemData *pItemData=NULL);
}

