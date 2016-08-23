#include <iostream>
#include <string>

#include <deque>
#include <vector>

typedef std::vector<std::vector<int> > Graph;

bool routeExists(const Graph& g, int start, int finish)
{
    std::deque<int> queue(1, start);
    std::vector<bool> visited(g.size(), false);

    while (!queue.empty())
    {
        int v = queue.front();
        if (v == finish)
            return true;
            
        queue.pop_front();
        visited[v] = true;

        for (unsigned i = 0; i < g[v].size(); ++i)
        {
            if (!visited[g[v][i]])
                queue.push_back(g[v][i]);
        }
    }
    
    return false;
}

int main(int argc, char* argv[])
{
    Graph g{ std::vector<int>{},
        std::vector<int>{0, 2},
        std::vector<int>{3},
        std::vector<int>{4, 5},
        std::vector<int>{},
        std::vector<int>{7},
        std::vector<int>{},
        std::vector<int>{6},
        std::vector<int>{7},
        std::vector<int>{8},
    };

    std::cout << std::boolalpha << routeExists(g, 1, 7);
    std::cout << std::boolalpha << routeExists(g, 9, 6);
    std::cout << std::boolalpha << routeExists(g, 1, 8);

    return 0;
}
