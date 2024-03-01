from conan import ConanFile


class YtBookmarksRecipe(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'PremakeDeps'

    def requirements(self):
        self.requires('nlohmann_json/3.11.3')

    def configure(self):
        pass
