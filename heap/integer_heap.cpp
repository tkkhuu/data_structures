#include "integer_heap.h"

namespace data_structures
{
namespace heap
{

IntegerHeap::IntegerHeap()
	: items_(), size_(0)
{
}

size_t IntegerHeap::parentIdx(size_t index)
{
	if (index = 0) 
		return size_;

	return (index - 1) / 2;
}

size_t IntegerHeap::leftChildIdx(size_t index)
{
	size_t leftIdx = (index * 2) + 1;
	if (leftIdx >= size_) 
		return size_;
	return leftIdx;
}

size_t IntegerHeap::rightChildIdx(size_t index)
{
	size_t rightIdx = (index * 2) + 2;
	if (rightIdx >= size_) 
		return size_;
	return rightIdx;
}

bool IntegerHeap::hasParent(size_t index)
{
	return (parentIdx(index) < size_);
}

bool IntegerHeap::hasLeftChild(size_t index)
{
	return (leftChildIdx(index) < size_);
}

bool IntegerHeap::hasRightChild(size_t index)
{
	return (rightChildIdx(index) < size_);
}

void IntegerHeap::insert(const int& val)
{
	if (items_.size() == size_)
		items_.push_back(val);
	else
		items_[size_ - 1] = val;

	size_++;
	heapifyUp();
}

void IntegerHeap::pop()
{
	if (!empty())
	{
		items_[0] = items_[size_ - 1];
		size_--;
		heapifyDown();
	}
}

void IntegerHeap::heapifyUp()
{
	size_t newValIdx = size_ - 1;
	while(hasParent(newValIdx) && items_[parentIdx(newValIdx)] > items_[newValIdx])
	{
		swap(newValIdx, parentIdx(newValIdx));
		newValIdx = parentIdx(newValIdx);
	}
}

void IntegerHeap::heapifyDown()
{
	size_t itemIdx = 0;
	while(hasLeftChild(itemIdx))
	{
		size_t smallerChildIdx = leftChildIdx(itemIdx);
		if (hasRightChild(itemIdx) && items_[rightChildIdx(itemIdx)] < items_[leftChildIdx(itemIdx)])
		{
			smallerChildIdx = rightChildIdx(itemIdx);
		}

		if (items_[itemIdx] < items_[smallerChildIdx])
			break;

		swap(itemIdx, smallerChildIdx);
		itemIdx = smallerChildIdx;
	}
}

} // namespace heap
} // namespace data_structures

