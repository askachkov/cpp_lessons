#pragma once
#include <iostream>

namespace optional
{
	class None
	{
	};

	template<typename T>
	class Some
	{
	private:
		union {
			T some;
			None none;
		} m_val;
		bool m_isSome;
	public:
		Some() {
			m_val.none = None();
			m_isSome = false;
		}

		Some(const T& val) {
			m_val.some = val;
			m_isSome = true;
		}

		operator bool() const {
			if(m_isSome) return true;
			return false;
		}

		bool operator==(const Some<T>& comp) const {
			std::cout << "\n m_isSome\t" << m_isSome << "left \t" << m_val.some <<" right \t" << comp.m_val.some << std::endl;
			if(!m_isSome)
				return false;
			return comp.m_val.some == m_val.some;
		}

		Some<T> none() const {
			return Some();
		}

		Some<T> operator/(const Some<T>& cmp) {
			m_val.some /= cmp.some;
			return *this;
		}

		void show() {
			if(m_isSome) {
				std::cout << "\n val:\t" << m_val.some << std::endl;
			} else {
				std::cout << "None" << std::endl;
			}
		}
	};


	template<typename T>
	class Optional {
	private:
		Some<T> m_val;
	public:
		Optional() : m_val(Some<T>()) {}
		Optional(const T& val) : m_val(Some<T>(val)) {}

		Optional<T> operator/(const Optional<T>& comp) const {
			Optional<T> res = Optional<T>();
			if(!m_val || !comp.m_val || (!comp.m_val == 0)) {
				return Optional();
			}
			res.m_val = m_val / comp.m_val;
			return res;
		}

		bool operator==(const Optional<T>& comp) const {
			if(!m_val || !comp.m_val)
				return false;
			std::cout<<"Enetered"<<std::endl;
			return m_val == comp.m_val;
		}

		void show() {
			m_val.show();
		}
	};
}
