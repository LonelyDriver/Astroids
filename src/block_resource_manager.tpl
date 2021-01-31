

namespace block {
    template<typename resource, typename identifier>
    template<typename ... Args>
    void ResourceManager<resource, identifier>::Load(const identifier& id, Args&& ... args) {
        std::unique_ptr<resource> ptr = std::make_unique<resource>();

        ptr->Load(std::forward<Args>(args)...);

        if(_dict.emplace(id, std::move(ptr)).second == false) {
            throw BlockException(
                "Could not emplace in dict. Already loaded?",
                __PRETTY_FUNCTION__,
                __LINE__,
                0
            );
        }
    }

    template<typename resource, typename identifier>
    resource& ResourceManager<resource, identifier>::Get(const identifier& id) const {
        return *_dict.at(id);
    }
}