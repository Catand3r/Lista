#pragma once
#include <cstddef>
#include <iostream>

template <typename T> class List
{
  public:
    class Iterator
    {
        friend List;

      private:
        struct Node
        {
          public:
            Node(T value) : value_(value)
            {
            }

            T value_;
            Node *next_ = nullptr;
            Node *prev_ = nullptr;
        };

        Node *node_ = nullptr;

      public:
        Iterator() = default;

        Iterator(Node *node) : node_(node)
        {
        }

        Iterator operator++(int)
        {
            Iterator prev = *this;

            if (node_ != nullptr && node_->next_ != nullptr)
            {
                Node *i = node_->next_;
                this->node_ = i;
            }
            else
            {
                this->node_ = nullptr;
            }

            return prev;
        }

        T &operator->()
        {
            return node_->value_;
        }

        bool operator==(const Iterator &comparedIt)
        {
            return this->node_ == comparedIt.node_;
        }

        bool operator!=(const Iterator &comparedIt)
        {
            return this->node_ != comparedIt.node_;
        }
    };

  public:
    List() = default;
    ~List()
    {
        clear();
    }

    void clear()
    {
        auto i = firstNode_.node_;
        while (i != nullptr)
        {
            auto j = i->next_;
            delete i;
            i = j;
        }
    }

    bool isEmpty() const
    {
        return firstNode_.node_ == nullptr;
    }

    bool operator==(const List &comparedList) const
    {
        auto it1 = this->begin();
        auto it2 = comparedList.begin();
        while (it1 != this->end() && it2 != comparedList.end())
        {
            if (it1.node_->value_ != it2.node_->value_)
            {
                return false;
            }
            it1++;
            it2++;
        }
        return it1 == this->end() && it2 == comparedList.end();
    }

    std::size_t size() const
    {
        std::size_t size = 0;
        auto i = firstNode_.node_;
        while (i != nullptr)
        {
            size++;
            i = i->next_;
        }
        return size;
    }

    T first() const
    {
        if (isEmpty())
            throw("Node empty");
        else
            return firstNode_.node_->value_;
    }

    T last() const
    {
        if (isEmpty())
            throw("Node empty");
        else
            return lastNode_.node_->value_;
    }

    void push_back(const T &value)
    {
        auto newNode = new Iterator::Node(value);
        if (isEmpty())
        {
            firstNode_ = newNode;
            lastNode_ = newNode;
        }
        else
        {
            newNode->prev_ = lastNode_.node_;
            lastNode_.node_->next_ = newNode;
            lastNode_.node_ = newNode;
        }
    }

    void erase(Iterator it)
    {
        if (it.node_->next_ == nullptr)
        {
            if (firstNode_ == lastNode_)
            {
                firstNode_ = Iterator(nullptr);
                lastNode_ = Iterator(nullptr);
            }
            else
            {
                it.node_->prev_->next_ = nullptr;
                Iterator newLast(it.node_->prev_);
                lastNode_ = newLast;
            }
        }
        else if (it.node_->prev_ == nullptr)
        {
            it.node_->next_->prev_ = nullptr;
            Iterator newFirst(it.node_->next_);
            firstNode_ = newFirst;
        }
        else
        {
            it.node_->prev_->next_ = it.node_->next_;
            it.node_->next_->prev_ = it.node_->prev_;
        }

        delete it.node_;
    }

    void eraseIndex(int i)
    {
        auto it = firstNode_;
        for (int j = 0; j < i; j++)
        {
            it++;
        }
        erase(it);
    }

    Iterator begin() const
    {
        return firstNode_;
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }

    void print()
    {
        auto i = firstNode_.node_;
        int seqNumber = 1;
        while (i != nullptr)
        {
            std::cout << "Element o numerze: " << seqNumber << " to " << i->value_ << "\n";
            seqNumber++;
            i = i->next_;
        }
    }

  protected:
    Iterator firstNode_;
    Iterator lastNode_;
};
