require 'set'

class Node
    attr_accessor :adj
    
    def initialize
        @adj = []
    end
end

def route_exists(node1, node2)
    queue = Array.new
    queue << node1
    
    visited = Set.new
    
    until queue.empty?
        node = queue.pop
        if node == node2
            return true
        end
        
        visited << node
        
        node.adj.each { |adj_node| queue << adj_node unless visited.include?(adj_node) }
    end
    
    return false
end


graph = Array.new(10) { Node.new }
graph[1].adj << graph[0] << graph[2]
graph[2].adj << graph[3]
graph[3].adj << graph[4] << graph[5]
graph[5].adj << graph[7]
graph[7].adj << graph[6]
graph[8].adj << graph[7]
graph[9].adj << graph[8]

puts route_exists(graph[1], graph[7]);
puts route_exists(graph[9], graph[6]);
puts route_exists(graph[1], graph[8]);
