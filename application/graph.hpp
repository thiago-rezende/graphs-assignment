/**
 * @file graph.hpp
 * @author Thiago Rezende (thiago-rezende.github.io)
 * @brief A Simple Graph Implementation
 * @version 0.1
 * @date 2021-03-31
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

class graph
{
private:
    /* Graph Data */
    std::map<uint64_t, std::set<uint64_t>> m_data;

public:
    /* Iterators Types */
    using iterator = std::map<uint64_t, std::set<uint64_t>>::iterator;

    /* Iterators Functions */
    iterator begin() { return m_data.begin(); }
    iterator end() { return m_data.end(); }

    /* Constructors */
    graph() = default;
    graph(const std::map<uint64_t, std::set<uint64_t>> &data)
        : m_data(data){};

    /* Emplace Vertex and Connections */
    void emplace(const std::pair<uint64_t, std::set<uint64_t>> &data)
    {
        m_data.emplace(data);
    }

    /* Check Connection in Common */
    bool check_common_connection(uint64_t va, uint64_t vb, uint64_t vc)
    {
        iterator a_it = m_data.find(va);
        iterator b_it = m_data.find(vb);

        if (a_it == end() || b_it == end())
            return false;

        std::set<uint64_t>::iterator a_set_it = a_it->second.find(vc);
        std::set<uint64_t>::iterator b_set_it = b_it->second.find(vc);

        if (a_set_it == a_it->second.end() || b_set_it == b_it->second.end())
            return false;

        return true;
    }

    /* Check for Euler Cycle */
    bool is_euler_walkable()
    {
        uint64_t count_odds = 0;

        iterator graph_it;

        for (graph_it = begin(); graph_it != end(); ++graph_it)
            if (graph_it->second.size() % 2 == 1)
                count_odds++;

        return (count_odds == 0 || count_odds == 2);
    }

    /* Highest Degree Vertex */
    uint64_t highest_degree_vertex()
    {
        iterator graph_it = begin()++;

        uint64_t vertex = graph_it->first;
        uint64_t connections = graph_it->second.size();

        for (graph_it = begin(); graph_it != end(); ++graph_it)
        {
            if (graph_it->second.size() > connections)
            {
                vertex = graph_it->first;
                connections = graph_it->second.size();
            }
        }

        return vertex;
    }

    /* Lowest Degree Vertex */
    uint64_t lowest_degree_vertex()
    {
        iterator graph_it = begin()++;

        uint64_t vertex = graph_it->first;
        uint64_t connections = graph_it->second.size();

        for (graph_it = begin(); graph_it != end(); ++graph_it)
        {
            if (graph_it->second.size() < connections)
            {
                vertex = graph_it->first;
                connections = graph_it->second.size();
            }
        }

        return vertex;
    }
};
