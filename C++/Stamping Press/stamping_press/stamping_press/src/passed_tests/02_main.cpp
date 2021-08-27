int main()
{
  stampstream s(30,10);
  s << "HiThereThisIsAVeryLongSentenceThatRunsOffTheEdge";
  return 0;
}
