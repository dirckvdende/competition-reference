// Randomize the order of a list
// Note that this implementation is not perfect and
// should not be used for security purposes
template<class T>
void randomSort(vector<T> &list) {
    static auto rng = default_random_engine(
    time(nullptr));
    shuffle(all(list), rng);
}