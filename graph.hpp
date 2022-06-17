#ifndef GRAPH_IS_INCLUDED
#define GRAPH_IS_INCLUDED

#include <map>

template<typename key_type, typename value_type,
         typename weight_type>
class Graph {
public:

/*============================Node=============================*/
    class Node {
    public:

        Node() : pvalue{0}, edges{0} {}

        Node(const Node& n) : pvalue{n.pvalue},
                              edges{n.edges} {}
        
        Node(Node&& n) : pvalue{n.pvalue},
                         edges{std::move(n.edges)} {}

        friend class Graph<key_type, value_type, weight_type>;

        bool empty() const { return edges.empty(); }

        size_t size() const { return edges.size(); }

        value_type& value() { return pvalue; }

        void clear() { edges.clear(); }

        Node& operator=(const Node& n) {

            this->pvalue = n.pvalue;
            this->edges  = n.edges;

            return *this;
        }

        Node& operator=(Node&& n) {
            
            this->pvalue = n.pvalue;
            this->edges  = std::move(n.edges);

            return *this;
        }

        typename std::map<key_type, weight_type>::iterator iterator;
        typename std::map<key_type, weight_type>::iterator const citerator;

        auto begin() { return edges.begin(); }

        auto end() { return edges.end(); }

        auto cbegin() const { return edges.cbegin(); }

        auto cend() const { return edges.cend(); }

    private:

        value_type pvalue;
        std::map<key_type, weight_type> edges;
    };
/*=============================================================*/

    Graph() : pts{} {}

    Graph(const Graph& gr) : pts{gr.pts} {}

    Graph(Graph&& gr) : pts{std::move(gr.pts)} {}

    Graph& operator=(const Graph& gr) {

        this->pts = gr.pts;

        return *this;
    }

    Graph& operator=(Graph&& gr) {

        this->pts = std::move(gr.pts);

        return *this;
    }

    bool empty() const { return pts.empty(); }

    size_t size() const { return pts.size(); }

    void clear() { pts.clear(); }

    auto begin() { return pts.begin(); }

    auto end() { return pts.end(); }

    auto cbegin() const { return pts.cbegin(); }

    auto cend() const { return pts.cend(); }

private:
    std::map<key_type, Node> pts;
};

#endif // GRAPH_IS_INCLUDED
