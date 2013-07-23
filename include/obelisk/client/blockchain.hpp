#ifndef OBELISK_CLIENT_BLOCKCHAIN
#define OBELISK_CLIENT_BLOCKCHAIN

#include <bitcoin/bitcoin.hpp>
#include <obelisk/client/backend.hpp>

class blockchain_interface
{
public:
    blockchain_interface(backend_cluster& backend);
    void fetch_history(const bc::payment_address& address,
        bc::blockchain::fetch_handler_history handle_fetch,
        size_t from_height=0);
    void fetch_transaction(const bc::hash_digest& tx_hash,
        bc::blockchain::fetch_handler_transaction handle_fetch);
    void fetch_last_height(
        bc::blockchain::fetch_handler_last_height handle_fetch);
    void fetch_block_header(const bc::hash_digest& blk_hash,
        bc::blockchain::fetch_handler_block_header handle_fetch);
private:
    backend_cluster& backend_;
};

#endif
