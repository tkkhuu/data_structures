
#include "trie.h"

namespace data_structures
{
namespace trie
{

TrieNode::TrieNode() : isWord_(false){}

bool TrieNode::hasChild(const char& c)
{
	return (children_.find(c) != children_.end());
}

void TrieNode::addChild(const char& c)
{
	if (!hasChild(c))
	{
		children_[c] = new TrieNode();
	}
}

bool TrieNode::isWord()
{
	return isWord_;
}

void TrieNode::setWord()
{
	isWord_ = true;
}

TrieNode* TrieNode::getChild(const char& c)
{
	if (hasChild(c))
		return children_.at(c);

	return nullptr;
}

Trie::Trie() : root_(new TrieNode()){}

bool Trie::hasWord(const string& word)
{
	TrieNode* current = root_;
	for (const char& c : word)
	{
		if (!current->hasChild(c))
			return false;
		
		current = current->getChild(c);
	}

	return current->isWord();
}

bool Trie::hasPrefix(const string& prefix)
{
	TrieNode* current = root_;
	for (const char& c : prefix)
	{
		if (!current->hasChild(c))
			return false;
		current = current->getChild(c);
	}

	return true;
}

void Trie::addWord(const string& word)
{
	TrieNode* current = root_;
	for (const char& c : word)
	{
		current->addChild(c);
		current = current->getChild(c);
	}

	current->setWord();
}

}
}

