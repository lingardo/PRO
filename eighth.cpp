int Functor::count = 0;
mutex Functor::myMutex;
class Functor
{
private:
static int count;
static mutex SumMutex;
public:
// Ìåòîäè ôóíêòîðà
//...
void operator()(const blocked_range<int>& Range) const
{
mutex::scoped_lock lock;
lock.acquire(myMutex);
count++;
lock.release();
}
}; 
