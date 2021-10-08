class Trie
{

private:
    Trie *child[26] = {};
    bool endsHere = false;

public:
    Trie() {}

    void insert(string word)
    { // for insertion
        Trie *curr = this;

        for (auto s : word)
        {
            int index = s - 'a';
            if (!curr->child[index])
                curr->child[index] = new Trie(); // if link doesnt exist that is it is no such char exists there or it could marked true there and after that no char is there then we create a new node
            curr = curr->child[index];           // if it does exist so we are looking for next key character
        }
        curr->endsHere = true; // when insertion completes then mark as true
    }

    bool search(string word)
    { // for searching
        Trie *curr = this;

        for (char &s : word)
        {
            int index = s - 'a';

            if (!curr || !curr->child[index])
                return false;
            curr = curr->child[index];
        }
        //return true;  // cant return by this bcoz may that word continues more in letters eg: if we are finding geek  but there exists geeks
        return curr->endsHere;
    }

    bool startsWith(string prefix)
    { // for prefix
        Trie *curr = this;

        for (char &s : prefix)
        {
            int index = s - 'a';

            if (!curr->child[index])
                return false;
            //  if(!curr->child.count(index) ) return false;
            curr = curr->child[index];
        }
        return true;
    }
};