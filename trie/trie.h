# pragma once

namespace data_structures
{
namespace trie
{

class TrieNode
{
private:
	bool isWord_;
	std::unordered_map<char, TrieNode*> children_;
public:
	void addChild(const char& c);
	bool hasChild(const char& c);
	bool isWord() const;
	void setWord();
	TrieNode* getChild(const char& c);
};

class Trie
{
private:
	TrieNode* root_;
public:
	bool hasWord(const string& word);
	bool hasPrefix(const string& prefix);
	void addWord(const string& word);
};

}
}