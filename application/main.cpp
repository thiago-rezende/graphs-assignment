/**
 * @file main.cpp
 * @brief Application Entry Point
 *
 */

#include <graph.hpp>

/* Application Entry Point */
int main(int argc, char **argv)
{
    /* Profiles the Main Function */
    H_PROFILE_FUNCTION();

    /* Initialize Logger */
    Horus::Logger::init();

    /* Graph Testing */
    graph g;
    graph::iterator g_it;

    g.emplace({0, {1, 2, 3}});
    g.emplace({1, {0, 3}});
    g.emplace({2, {0, 3}});
    g.emplace({3, {0, 1, 2}});

    for (g_it = g.begin(); g_it != g.end(); ++g_it)
    {
        H_DEBUG("----");
        for (const int &f : g_it->second)
            H_DEBUG("[{}] {}", g_it->first, f);
    }

    H_DEBUG("Highest Degree Vertex: {}", g.highest_degree_vertex());
    H_DEBUG("Lowest Degree Vertex: {}", g.lowest_degree_vertex());

    if (g.check_common_connection(0, 1, 3))
        H_DEBUG("Check Common Connection: 0 -> 3 <- 1");

    H_DEBUG("Is Euler Walkable: {}", g.is_euler_walkable() ? "True" : "False");

    return 0;
}
