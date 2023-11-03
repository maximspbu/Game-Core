#ifndef QUEST_ITEMS_H
#define QUEST_ITEMS_H
class Quest_items{
    protected:
        struct Stats{
            bool complete;
        } stats;
    public:
        Quest_items(Stats stats);
        Stats get_stats();
};
#endif