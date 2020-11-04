#pragma once

namespace data_structures
{

namespace heap
{
	class IntegerHeap
	{
	private:
		std::vector<int> items_;
		size_t size_;

		void heapifyUp();
		void heapiFyDown();

		size_t parentIdx(size_t index);
		size_t leftChildIdx(size_t index);
		size_t rightChildIdx(size_t index);

		bool hasParent(size_t index);
		bool hasLeftChild(size_t index);
		bool hasRightChild(size_t index);

		void swap(const size_t& idxA, const size_t& idxB);
	
	public:
		IntegerHeap();
		bool empty() {return size_ == 0;}
		int top() const {return items_[0]};
		void pop();
		void insert(const int& val);

	};
}
}