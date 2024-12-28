#pragma once

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
            if (node_ != nullptr && node_->next_ != nullptr)
            {
                Node *i = node_->next_;
                Iterator it(i);
                return it;
            }
            else
            {
                Iterator it(nullptr);
                return it;
            }
        }

        T &operator->()
        {
            return node_->value_;
        }
    };

  public:
    List() = default;
    ~List()
    {
        auto i = firstNode_.node_;
        while (i != nullptr)
        {
            auto j = i->next_;
            delete i;
            i = j;
        }
    }

    bool isEmpty()
    {
        return firstNode_.node_ == nullptr;
    }

    T first()
    {
        if (isEmpty())
            throw("Node empty");
        else
            return firstNode_.node_->value_;
    }

    T last()
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

  protected:
    Iterator firstNode_;
    Iterator lastNode_;
};
