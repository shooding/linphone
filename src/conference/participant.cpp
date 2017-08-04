/*
 * participant.cpp
 * Copyright (C) 2017  Belledonne Communications SARL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "object/object-p.h"

#include "participant.h"

using namespace std;

LINPHONE_BEGIN_NAMESPACE

// =============================================================================

class ParticipantPrivate : public ObjectPrivate {
public:
	~ParticipantPrivate ();

	LinphoneAddress *addr = nullptr;
	bool isAdmin = false;
};

ParticipantPrivate::~ParticipantPrivate() {
	if (addr) linphone_address_unref(addr);
}

// =============================================================================

Participant::Participant (LinphoneAddress *addr) : Object(*new ParticipantPrivate) {
	L_D(Participant);
	if (addr) d->addr = linphone_address_ref(addr);
}

// -----------------------------------------------------------------------------

LinphoneAddress * Participant::getAddress () const {
	L_D(const Participant);
	return d->addr;
}

// -----------------------------------------------------------------------------

bool Participant::isAdmin () const {
	L_D(const Participant);
	return d->isAdmin;
}

void Participant::setAdmin (bool isAdmin) {
	L_D(Participant);
	d->isAdmin = isAdmin;
}

LINPHONE_END_NAMESPACE
