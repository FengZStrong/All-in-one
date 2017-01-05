template <typename T>
void removeElems(T &lst)
{
	typename T::iterator iter = lst.begin();
	while (iter != lst.end())
	{
		iter = lst.erase(iter);
		//if (iter != lst.end())
			//++iter;
	}
}