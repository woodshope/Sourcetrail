#ifndef INDEXER_COMMAND_JAVA_H
#define INDEXER_COMMAND_JAVA_H

#include <vector>

#include "data/indexer/IndexerCommand.h"
#include "utility/file/FilePath.h"

class IndexerCommandJava
	: public IndexerCommand
{
public:
	static std::string getIndexerKindString();

	IndexerCommandJava(
		const FilePath& sourceFilePath,
		const std::set<FilePath>& indexedPaths,
		const std::set<FilePath>& excludedPaths,
		const std::vector<FilePath>& classPath);
	virtual ~IndexerCommandJava();

	std::string getKindString() const override;

	std::vector<FilePath> getClassPath() const;

	bool preprocessorOnly() const override;
	void setPreprocessorOnly(bool preprocessorOnly) override;

private:
	std::vector<FilePath> m_classPath;
};

#endif // INDEXER_COMMAND_JAVA_H
