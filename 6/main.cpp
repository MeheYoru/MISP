#include <bits/stdc++.h>
bool sign(int i)
{
    return (i >= 0 ? 1 : 0);
}

int main(int argc, const char **argv)
{

    if (argc != 2)
    {
        return -1;
    }
    std::fstream file(argv[1]);
    if (!file)
        return -1;

    int N, a, b, temp, maxm;
    std::vector<int> list, list_cut, list_cut_no_even;

    file >> N >> a >> b;
    maxm = a;
    for (size_t i = 0; i < N; i++)
    {
        file >> temp;
        list.push_back(temp);
    }
    maxm = list[0];
    for (size_t i = 0; i < N; i++)
    {
        temp = list[i];
        if (temp < a || temp > b)
            continue;
        maxm = std::max(maxm, temp);
        list_cut.push_back(temp);
    }
    int del_pos = -1, del_val = -1;
    bool flag = 0, flag2 = 0;
    for (size_t i = 0; i < list_cut.size(); i++)
    {
        if (list_cut[i] == maxm && !flag2)
        {
            flag = 1;
            flag2 = 1;
        }
        if ((list_cut[i] % 2 == 0) && flag)
        {
            flag = 0;
            del_pos = i;
            del_val = list_cut[i];
            continue;
        }
        list_cut_no_even.push_back(list_cut[i]);
    }

    for (auto it : list)
        std::cout << it << " ";
    std::cout << std::endl;
    for (auto it : list_cut)
        std::cout << it << " ";
    std::cout << std::endl;
    for (auto it : list_cut_no_even)
        std::cout << it << " ";
    std::cout << std::endl;
    std::cout << del_pos << " " << del_val << " " << std::count_if(list_cut_no_even.begin(), list_cut_no_even.end(), sign) << " " << list_cut_no_even.size() - std::count_if(list_cut_no_even.begin(), list_cut_no_even.end(), sign) << std::endl;
}