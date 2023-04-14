#pragma once
#include "../GameEngineConsole/GameEngineArray.h"
#include "../GameEngineConsole/ConsoleGameObject.h"
#include <vector>
#include <list>

class ConsoleObjectManager
{
public:
	template<typename ObjectType>
	static ObjectType* CreateConsoleObject(int _Order)
	{
		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}
		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();
		// Player* NewObject = new Player();
		Group.ReSize(Group.Count() + 1);
		Group[Group.Count() - 1] = NewObject;

		return NewObject;
	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>((int)_Order);
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();

	template<typename EnumType>
	static std::list<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[(int)_Order];
	}

	static std::list<ConsoleGameObject*>& GetGroup(int _Order)
	{
		return AllObject[_Order];
	}


private:
	// constrcuter destructer
	ConsoleObjectManager();
	~ConsoleObjectManager();

	// delete Function
	ConsoleObjectManager(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager(ConsoleObjectManager&& _Other) noexcept = delete;
	ConsoleObjectManager& operator=(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager& operator=(ConsoleObjectManager&& _Other) noexcept = delete;

	static std::vector<std::list<ConsoleGameObject*>> AllObject;

};

