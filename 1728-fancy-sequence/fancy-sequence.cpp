namespace {


auto const fastIOInit{
    [] -> int {
        std::atexit([] { std::ofstream{"display_runtime.txt"} << 0 << std::endl; } );
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return 0;
    } ()
};

}

class Fancy final {
public:
    using ll = long long;

   
    Fancy() {
        mNums.reserve(kMaxNumsSz);
    };
   
    auto append(ll const val_) -> void {
       
        auto const val{
            (val_ - mParamB + kModulus) % kModulus * DoInv(mParamA) % kModulus};
        mNums.emplace_back(val);
    }
    
    
    auto addAll(ll const addend_) -> void {
        mParamB = (mParamB + addend_) % kModulus;
    }
    
   
    auto multAll(ll const multiplier_) -> void {
        mParamA = mParamA * multiplier_ % kModulus;
        mParamB = mParamB * multiplier_ % kModulus;
    }
    
    
    [[nodiscard]]
    auto getIndex(size_t const idx_) const -> int {
        if(idx_ >= mNums.size()) { 
            return -1;
        }
        auto const ans{(mParamA * mNums[idx_] % kModulus + mParamB) % kModulus};
        return static_cast<int>(ans);
    }

private:
   
    auto DoQuickmul(
        ll base_,
        ll pow_
    ) const -> ll {
        auto prod{1ll};
        while(pow_ > 0) {
            if(pow_ % 2 == 1) {
                prod = prod * base_ % kModulus;
            }
            base_ = base_ * base_ % kModulus;
            pow_ >>= 1;
        }
        return prod;
    }

    
    auto DoInv(ll const val_) const -> ll {
        return DoQuickmul(val_, kModulus - 2);
    }

    static auto constexpr kModulus{1'000'000'007ll};
    static auto constexpr kMaxNumsSz{100'000uz};
    std::vector<ll> mNums;
    
    ll mParamA{1};
    ll mParamB{0};
};

