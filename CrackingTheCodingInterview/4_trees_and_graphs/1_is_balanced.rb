class Node
  attr_accessor :child_left, :child_right

  def initialize(child_left, child_right)
    @child_left = child_left
    @child_right = child_right
  end
end

def get_balanced_and_height(root)
  return [true, 0] unless root

  left_balanced_and_height = get_balanced_and_height(root.child_left)   
  right_balanced_and_height = get_balanced_and_height(root.child_right)

  balanced = left_balanced_and_height[0] && right_balanced_and_height[0] && (left_balanced_and_height[1] - right_balanced_and_height[1]).abs <= 1
  height = [left_balanced_and_height[1], right_balanced_and_height[1]].max + 1

  [balanced, height]
end

def is_balanced(root)
  get_balanced_and_height(root)[0]
end


tree1 = Node.new( 
    Node.new( 
        Node.new( 
            Node.new( nil, nil ), 
            Node.new( nil, nil ) ),
        Node.new( 
            Node.new( nil, nil ),
            nil ) ),
    Node.new( 
        Node.new( 
            Node.new( nil, nil ),
            Node.new( nil, nil ) ),
        Node.new( 
            Node.new( nil, nil ),
            Node.new( 
                Node.new( nil, nil ),
                nil ) ) ) )

puts is_balanced(tree1)

tree2 = Node.new( 
    Node.new( 
        Node.new( 
            Node.new( nil, nil ), 
            Node.new( nil, nil ) ),
        Node.new( 
            Node.new( nil, nil ),
            nil ) ),
    Node.new( 
        Node.new( 
            Node.new( nil, nil ),
            Node.new( nil, nil ) ),
        Node.new( 
            Node.new( nil, nil ),
            Node.new( 
                Node.new( Node.new( nil, nil ), nil ),
                nil ) ) ) )

puts is_balanced(tree2)
