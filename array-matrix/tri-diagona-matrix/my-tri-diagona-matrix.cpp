//三对角矩阵的方法
//采用逐条对角线映射

template <typename anytype>
anytype TriDiagonaMatrix<anytype>::get(int i, int j) const
{
  if( i < 1 || i > n || j < 1  || j > n)
  {
    ostream os;
    os << "The index is not in bounds";
    return os.c_str();
  }
  
  //确定要返回的元素
  switch(i - j)
  {
    case 1: return m_element[i - 2]; break;             //下对角线
    case 0: return m_element[n + i - 2]; break;         //主对角线
    case -1: return m_element[2 * n + i - 2]; break;    //上对角线
    default: return 0;
  }
}
