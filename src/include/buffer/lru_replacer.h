#ifndef MINISQL_LRU_REPLACER_H
#define MINISQL_LRU_REPLACER_H

#include <list>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "buffer/replacer.h"
#include "common/config.h"

using namespace std;

/**
 * LRUReplacer implements the Least Recently Used replacement policy.
 */
class LRUReplacer : public Replacer {
public:
  /**
   * Create a new LRUReplacer.
   * @param num_pages the maximum number of pages the LRUReplacer will be required to store
   */
  explicit LRUReplacer(size_t num_pages);

  /**
   * Destroys the LRUReplacer.
   */
  ~LRUReplacer() override;

  bool Victim(frame_id_t *frame_id) override;

  void Pin(frame_id_t frame_id) override;

  void Unpin(frame_id_t frame_id) override;

  size_t Size() override;

private:
  // add your own private member variables here
  size_t num_pages;
  unordered_map<frame_id_t, int> lru_list_;//the lru list, contaning frame_id that can be victimed, "int" is their "old factor"
};

#endif  // MINISQL_LRU_REPLACER_H
