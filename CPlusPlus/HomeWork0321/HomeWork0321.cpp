// HomeWork0321.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>


class Object
{
    //private:
    char ObjectName[20] = {};
    int ObjectHp = 0;
    int ObjectAtt = 0;
    bool Player = false;
public:

    bool SetPlayer()
    {
        return Player = true;
    }

    bool GetPlayer()
    {
        return Player;
    }

    void SetName(const char* _Name)
    {
        for (int Count = 0; 0 != _Name[Count]; Count++)
        {
            ObjectName[Count] = _Name[Count];
        }
    }
    

    void SetHp(int _Hp)
    {
        ObjectHp = _Hp;
    }

    void SetAtt(int _Att)
    {
        ObjectAtt = _Att;
    }

    int GetHp()
    {
        return ObjectHp;
    }

    int GetAtt()
    {
        return ObjectAtt;
    }

    int AttackHp(int _Att)
    {
       return ObjectHp -= _Att;
    }

    void StatusRender()
    {
        printf_s("%s의 스테이터스 ------------\n", ObjectName);
        printf_s("공격력 : %d\n", ObjectAtt);
        printf_s("체력 : %d\n", ObjectHp);
        printf_s("---------------------------\n");
    }

    void Damage(Object& _AttObject, Object& _DefObject)
    {
        system("cls");
        _DefObject.SetHp(_DefObject.AttackHp(ObjectAtt));

        if (GetPlayer())
        {
            StatusRender();
            _DefObject.StatusRender();
            printf_s("%s가 공격을 시작합니다\n", ObjectName);
            printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefObject.ObjectName, GetAtt());
        }
        else
        {
            _DefObject.StatusRender();
            StatusRender();
            printf_s("%s가 공격을 시작합니다\n", _DefObject.ObjectName);
            printf_s("%s가 %d의 데미지를 입었습니다.\n", ObjectName, _DefObject.GetAtt());
            printf_s("%s가 공격을 시작합니다\n", ObjectName);
            printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefObject.ObjectName, GetAtt());
        }

    }

};

int main()
{
    Object Player;
    Player.SetName("Player");
    Player.SetPlayer();
    Player.SetHp(100);
    Player.SetAtt(10);

    Object Monster;
    Monster.SetName("Monster");
    Monster.SetHp(100);
    Monster.SetAtt(10);

    /* {
        Player.StatusRender();
        _getch();

        Monster.StatusRender();
        _getch();

        Player.Damage(Monster);
        Monster.Damage(Player);
    }*/
     
    while (true)
    {  
        system("cls");

        Player.StatusRender();
        Monster.StatusRender();
        _getch();

        Player.Damage(Player, Monster);
        _getch();



        if (0 >= Monster.GetHp())
        {
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        Monster.Damage(Monster, Player);
        _getch();

        if (0 >= Player.GetHp())
        {
            printf_s("플레이어가 죽었습니다.");
            printf_s("몬스터의 승리입니다.");
            _getch();
            break;
        }
    }

}
