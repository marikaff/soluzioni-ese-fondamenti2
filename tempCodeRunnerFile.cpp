bool operator==(const stack_con_interessi& other) const{
        return (t==other.t && size==other.size && capacity==other.capacity && stack==other.stack);
    }