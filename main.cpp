#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class UserManager
{
    map<int, string> manager;
    vector<int> ids;

    int generateID()
    {
        int num = rand();
        while (find(ids.begin(), ids.end(), num) != ids.end())
        {
            num = rand();
        }
        ids.push_back(num);
        return num;
    }

public:
    UserManager()
    {
        srand(time(0));
    }

    int addUser(string name)
    {
        int id = generateID();
        manager[id] = name;
        return id;
    }

    string getUser(int id)
    {
        if (manager.find(id) != manager.end())
        {
            return manager[id];
        }
        else
        {
            return "None";
        }
    }

    bool deleteUser(int id)
    {
        if (manager.find(id) != manager.end())
        {
            manager.erase(id);
            return true;
        }
        return false;
    }

    vector<int> findUserByName(string name)
    {
        vector<int> list;
        for (pair<int, string> pair : manager)
        {
            if (pair.second == name)
            {
                list.push_back(pair.first);
            }
        }
        return list;
    }
};

int main()
{
    UserManager userManager = UserManager();

    int id1 = userManager.addUser("Jarasar");
    int id2 = userManager.addUser("Adil");
    int id3 = userManager.addUser("Jarasar");

    cout << userManager.getUser(id1) << "\n";
    cout << userManager.getUser(id2) << "\n";
    cout << userManager.getUser(999) << "\n";

    for (int i : userManager.findUserByName("Jarasar"))
    {
        cout << i << " ";
    }
    cout << "\n";

    for (int j : userManager.findUserByName("Baha"))
    {
        cout << j << " ";
    }
    cout << "\n";

    cout << userManager.deleteUser(id2) << "\n";
    cout << userManager.deleteUser(999) << "\n";

    cout << userManager.getUser(id2);
}