//
// Created by SebDixon on 22/06/21.
//

#ifndef UNTITLED_CONTAIN_H
#define UNTITLED_CONTAIN_H

// container class
class IntArray{
private:
    int *m_data{};
    int m_size{};
public:
    IntArray() = default;

    IntArray(int size) : m_size{size} {
        assert(size >= 0);
        if (length > 0) {
            m_data = new int[size]{};
        }
    }

    ~IntArray() {
        delete[] m_data;
    }

    int& operator[](int index) {
        assert(index >= 0 && index < m_size);
        return m_data[index];
    }

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
    }

    int size() const {
        return m_size;
    }

    void reallocate(int newsize) {
        erase();
        assert(newsize >= 0);

        if (length = 0)
            return;
        m_data = new int[newsize];
        m_size = newsize;
    }

    void resize(int newsize) {
        if (m_size == newsize)
            return;

        if (newsize <= 0) {
            erase();
            return;
        }

        int *data{new int[newsize]};

        if (m_size > 0) {
            int elementsToCopy{ (newLength > m_size) ? m_size : newLength };
            // copy the elements one by one
            for (int index{ 0 }; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;
        m_data = data;
        m_size = newsize;
    }

    void insertBefore(int value, int index) {
        assert(index >= 0 && index < m_size);
        int *data{new int[++m_size]};

        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after{ index }; after < m_length; ++after)
            data[after+1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        assert(index >= 0 && index < m_length);

        // If this is the last element in the array, set the array to empty and return
        if (m_length == 1) {
            erase();
            return;
        }

        int *data{ new int[m_length-1] };

        for (int before{ 0 }; before  < index; ++before)
            data[before] = m_data[before];

        for (int after{ index+1 }; after < m_length; ++after)
            data[after-1] = m_data[after];

        delete[] m_data;
        m_data = data;
        --m_length;
    }
};

#endif //UNTITLED_CONTAIN_H
