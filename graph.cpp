#include "graph.hpp"
#include <utility>

template<typename key_type, typename value_type,
         typename weight_type>
size_t Graph<key_type, value_type, weight_type>::degree_out(key_type key) const {

    return this->pts.at(key).size();
}

template<typename key_type, typename value_type,
         typename weight_type>
size_t Graph<key_type, value_type, weight_type>::degree_in(key_type key) const {

    size_t count = 0;
    
    for (auto it = pts.cbegin(); it != pts.cend(); ++it)
        if (it->second.count(key))
            ++count;

    return count;
}

template<typename key_type, typename value_type,
         typename weight_type>
bool Graph<key_type, value_type, weight_type>::loop(key_type key) const {

    for (auto it =  pts.at(key).second.cbegin();
              it != pts.at(key).second.cend(); ++it)
        if (it->first == key)
            return true;

    return false;
}

template<typename key_type, typename value_type,
         typename weight_type>
void Graph<key_type, value_type, weight_type>::swap(
        Graph<key_type, value_type, weight_type> &g) {

    Graph<key_type, value_type, weight_type> tmp(g);
    g = *this;
    *this = tmp;
}

template<typename key_type, typename value_type,
         typename weight_type>
void swap(Graph<key_type, value_type, weight_type>& g1,
        Graph<key_type, value_type, weight_type>& g2) {

    g1.swap(g2);
}

template<typename key_type, typename value_type,
         typename weight_type>
std::pair<typename std::map<key_type,
          typename Graph<key_type, value_type, weight_type>::Node>::iterator,
          bool>
Graph<key_type, value_type, weight_type>::insert_node(key_type key, value_type val) {
    
    auto iter = this->pts.find(key);
    if (iter != this->pts.end())
        return std::make_pair(iter, false);

    auto result = this->pts.insert( {key, Node()} );

    this->pts.at(key).pvalue = val;

    return std::make_pair(result, true);
}
