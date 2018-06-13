#pragma once
#include "stdafx.h"
#include <vector>

template <typename T>
class Set {
	//friend class SetIterator;
private:
	std::vector<T> _items;

public:
	Set() {}
	~Set() {}

	void Add(T item) {
		_items.push_back(item);
	}

	void Remove(T item) {
		int index = 0;
		for (T i : _items) {
			if (i == item) {
				_items.erase(_items.begin() + index);
				return;
			}
			index++;
		}
	}

	bool Contains(T item) {
		for (T i : _items) {
			if (i == item)
				return true;
		}
		return false;
	}

	void UnionWith(Set* set) {
		for (T* item : *set) {
			if (!Contains(*item))
				Add(*item);
		}
	}

	void IntersectWith(Set* set) {
		std::vector<T> res;
		for (T* item : *set) {
			if (Contains(*item))
				res.push_back(*item);
		}

		_items = res;
	}

	void ExceptWith(Set* set) {
		for (T* item : *set) {
			if (Contains(*item))
				Remove(*item);
		}
	}

	class  SetIterator : public std::iterator<std::output_iterator_tag, T, int, const T*, T> {
	private:
		std::vector<T>* _iteratorItems;
		int _currIndex;

	public:
		/*explicit*/ SetIterator(std::vector<T>* items, int index) {
			_currIndex = index;
			_iteratorItems = items;
		}

		SetIterator& operator++() {
			_currIndex++;
			return *this;
		}

		SetIterator operator++(int) {
			SetIterator retval = *this;
			++(*this);
			return retval;
		}

		bool operator==(SetIterator other) const {
			return _currIndex == other._currIndex;
		}

		bool operator!=(SetIterator other) const {
			return !(*this == other);
		}

		T* operator*() {
			return &(*_iteratorItems)[_currIndex];
		}
	};

	SetIterator begin() {
		SetIterator iterator = { &_items, 0 };
		return SetIterator(&_items, 0);
	}

	SetIterator end() {
		return SetIterator(&_items, _items.size());
	}

};