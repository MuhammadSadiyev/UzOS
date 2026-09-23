// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#include "base/random.h"

#include <QtCore/QRandomGenerator>
#include <cstring>

namespace base {
namespace {

template <typename Next>
int RandomIndex(int count, Next &&next) {
	Expects(count > 0);

	if (count == 1) {
		return 0;
	}
	const auto max = (std::numeric_limits<uint32>::max() / count) * count;
	while (true) {
		const auto random = next();
		if (random < max) {
			return int(random % count);
		}
	}
}

} // namespace

void RandomFill(bytes::span bytes) {
	const auto ptr = reinterpret_cast<quint32*>(bytes.data());
	const auto count = bytes.size() / sizeof(quint32);
	const auto rem = bytes.size() % sizeof(quint32);
	QRandomGenerator::global()->fillRange(ptr, count);
	if (rem) {
		const auto tail = QRandomGenerator::global()->generate();
		std::memcpy(bytes.data() + count * sizeof(quint32), &tail, rem);
	}
}

int RandomIndex(int count) {
	return RandomIndex(count, [] { return  RandomValue<uint32>(); });
}

int RandomIndex(int count, BufferedRandom<uint32> buffered) {
	return RandomIndex(count, [&] { return buffered.next(); });
}

void RandomAddSeed(bytes::const_span bytes) {
	// No-op: QRandomGenerator does not need external seeding.
	(void)bytes;
}

} // namespace base
