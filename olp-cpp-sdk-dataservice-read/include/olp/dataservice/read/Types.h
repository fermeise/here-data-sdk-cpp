/*
 * Copyright (C) 2019-2020 HERE Europe B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 * License-Filename: LICENSE
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

#include <olp/core/client/ApiError.h>
#include <olp/core/client/ApiNoResult.h>
#include <olp/core/client/ApiResponse.h>

#include <olp/dataservice/read/AggregatedDataResult.h>
#include <olp/dataservice/read/PrefetchPartitionsResult.h>
#include <olp/dataservice/read/PrefetchStatus.h>
#include <olp/dataservice/read/model/Catalog.h>
#include <olp/dataservice/read/model/Data.h>
#include <olp/dataservice/read/model/Messages.h>
#include <olp/dataservice/read/model/Partitions.h>
#include <olp/dataservice/read/model/VersionInfos.h>
#include <olp/dataservice/read/model/VersionResponse.h>

namespace olp {
namespace dataservice {
namespace read {

class PrefetchTileResult;

/// The response template type.
template <typename ResultType>
using Response = client::ApiResponse<ResultType, client::ApiError>;

/// The callback template type.
template <typename ResultType>
using Callback = std::function<void(Response<ResultType>)>;

/// An alias for the catalog configuration.
using CatalogResult = model::Catalog;
/// The catalog configuration response type.
using CatalogResponse = Response<CatalogResult>;
/// The callback type of the catalog configuration response.
using CatalogResponseCallback = Callback<CatalogResult>;

/// An alias for the catalog version result.
using CatalogVersionResult = model::VersionResponse;
/// The catalog version response type.
using CatalogVersionResponse = Response<CatalogVersionResult>;
/// The callback type of the catalog version response.
using CatalogVersionCallback = Callback<CatalogVersionResult>;

/// An alias for the partition metadata result.
using PartitionsResult = model::Partitions;
/// The partition metadata response type.
using PartitionsResponse = Response<PartitionsResult>;
/// The callback type of the partition metadata response.
using PartitionsResponseCallback = Callback<PartitionsResult>;

/// The `Data` alias type.
using DataResult = model::Data;
/// The data response alias.
using DataResponse = Response<DataResult>;
/// The callback type of the data response.
using DataResponseCallback = Callback<DataResult>;

/// The aggregated data response alias.
using AggregatedDataResponse = Response<AggregatedDataResult>;
/// The callback type of the aggregated data response.
using AggregatedDataResponseCallback = Callback<AggregatedDataResult>;

/// An alias for the prefetch tiles result.
using PrefetchTilesResult = std::vector<std::shared_ptr<PrefetchTileResult>>;
/// The prefetch tiles response type.
using PrefetchTilesResponse = Response<PrefetchTilesResult>;
/// The callback type of the prefetch completion.
using PrefetchTilesResponseCallback = Callback<PrefetchTilesResult>;
/// The callback type for the prefetch status update.
using PrefetchStatusCallback = std::function<void(PrefetchStatus)>;

/// The prefetch partitions response type.
using PrefetchPartitionsResponse = Response<PrefetchPartitionsResult>;
/// The callback type of the prefetch completion.
using PrefetchPartitionsResponseCallback = Callback<PrefetchPartitionsResult>;
/// The callback type for the prefetch status update.
using PrefetchPartitionsStatusCallback =
    std::function<void(PrefetchPartitionsStatus)>;

/// The subscribe ID type of the stream layer client.
using SubscriptionId = std::string;
/// The subscribe response type of the stream layer client.
using SubscribeResponse = Response<SubscriptionId>;
/// The subscribe completion callback type of the stream layer client.
using SubscribeResponseCallback = Callback<SubscriptionId>;

/// The unsubscribe response type of the stream layer client.
using UnsubscribeResponse = Response<SubscriptionId>;
/// The unsubscribe completion callback type of the stream layer client.
using UnsubscribeResponseCallback = Callback<SubscriptionId>;

/// An alias for the messages result.
using MessagesResult = model::Messages;
/// The poll response type of the stream layer client.
using PollResponse = Response<MessagesResult>;
/// The poll completion callback type of the stream layer client.
using PollResponseCallback = Callback<MessagesResult>;

/** @brief An alias for the seek response result.
 *
 * The status of the HTTP request.
 */
using SeekResult = int;
/// The seek response type of the stream layer client.
using SeekResponse = Response<SeekResult>;
/// The seek completion callback type of the stream layer client.
using SeekResponseCallback = Callback<SeekResult>;

/// An alias for the version result.
using VersionsResult = model::VersionInfos;
/// The versions list of metadata response type for the versioned client.
using VersionsResponse = Response<VersionsResult>;
/// The versions list of metadata callback type for the versioned client.
using VersionsResponseCallback = Callback<VersionsResult>;

/// The list of tile keys.
using TileKeys = std::vector<geo::TileKey>;
}  // namespace read
}  // namespace dataservice
}  // namespace olp
